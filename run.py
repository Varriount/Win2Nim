import subprocess
import itertools
import os
from time import sleep
import re


GCC_HEADER = r"""
# 1 "<stdin>"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "\./common\.h" 1
# 1 "<command-line>" 2
# 1 "<stdin>"\n
""".strip()

# 1 "<stdin>"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "./common.h" 1
# 19 "./common.h"
# 57 "./common.h"
# 1 "<command-line>" 2
# 1 "<stdin>"

config = {
    "defines": {
    },
    "undefines": [
    ],
    "replacements": {
        # r"":
        #     r"",
        r"\n *#pragma warning\(pop\)":
            r"",
        r"\n *#pragma (once|endregion)":
            r"",
        r"\n *#pragma region (Application|Desktop) Family":
            r"",
        r'( *)#define(.+)\'([\w\d]{0,4})\'':
            r'\1#define\2nimCharArray("\3")',
        r'( *)#endif( +)(\w.*)':
            r'\1#endif\2// \3',
        r"#if WINAPI_FAMILY_PARTITION\((.*)\)":
            r"#if WINAPI_FAMILY_PARTITION // \1"
  }
}

# Directories to search through
start_dirs = ['shared', 'ucrt', 'um', 'winrt']

# Calculate CPPP arguments
cppp_args = ['cppp']
for symbol, value in config['defines'].items():
    cppp_args.append('-D')
    if value:
        cppp_args.append(symbol + "=" + value)
    else:
        cppp_args.append(symbol)
for symbol in config['undefines']:
    cppp_args.append('-U')
    cppp_args.append(symbol)

with open('common.h', 'r') as fh:
    for i, line in enumerate(fh, 1):
        if line.startswith("#define"):
            m = re.match(r'^\s*#define\s+(\w+)(?:\(.*?\))?(?:\s+([0-9]+))?', line)
            symbol = m.group(1)
            value = m.group(2)

            cppp_args.append('-D')
            if value:
                cppp_args.append(symbol + "=" + value)
            else:
                cppp_args.append(symbol)

        elif line.startswith("#undef"):
            m = re.match(r'^\s*#undef\s+(.+)', line)
            cppp_args.append('-U')
            cppp_args.append(m.group(1))

        elif line.strip() == "" or re.match(r'\s*//', line):
            pass
        else:
            raise Exception("Non-matching line in common.h, line {}, '{}'".format(i, line))


gcc_args = ['gcc', '-xc', '-undef', '-CC', '-E', '-imacros', 'common.h', '-']


target_trees = itertools.chain.from_iterable(map(os.walk, start_dirs))
for dirpath, dirnames, filenames in target_trees:
    for name in filenames:
        if not name.endswith('.h'):
            continue

        filepath = os.path.join(dirpath, name)
        print("Processing", filepath)

        with open(filepath, 'r') as fh:
            contents = fh.read()

        # Run through replacements
        for match, replacement in config['replacements'].items():
            contents = re.sub(match, replacement, contents)
        
        # Run CPPP tool
        cppp_process = subprocess.run(
            cppp_args,
            input=contents,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            universal_newlines = True,
            check = False
        )
        contents = cppp_process.stdout
        print(cppp_process.stderr)

        # Comment out defines
        contents = re.sub(r'^([ \t]*)#', r'\1pound#', contents, flags=re.MULTILINE)

        # Run GCC
        gcc_process = subprocess.run(
            gcc_args,
            input=contents,
            stdout = subprocess.PIPE,
            stderr = subprocess.PIPE,
            universal_newlines = True,
            check = False
        )
        contents = gcc_process.stdout
        print(gcc_process.stderr)

        # Uncomment defines
        contents = re.sub(r"^([ \t]*)pound#", r"\1#", contents, flags=re.MULTILINE)

        # Remove GCC Header
        contents = re.sub(r"(\n|^) *# \d{1,2} .*", "", contents)
        
        # Remove redundant defines
        contents = re.sub(r'\n *#define +(.*) +\1$', '', contents, flags=re.MULTILINE)
        contents = re.sub(r'\n *#define *$', '', contents, flags=re.MULTILINE)

        # Remove redundant ifdefs
        contents = re.sub(r'\n *#if(def)? +.+(\n *)+#endif.*', '', contents, flags=re.MULTILINE)

        # Remove extra whitespace
        contents = re.sub(r'(\n *){5,}', '', contents, flags=re.MULTILINE)

        with open(filepath + '.out', 'w') as fh:
            fh.write(contents)


    
