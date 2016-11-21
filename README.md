Requires:
 - GCC
 - Python 3.5
 - [Partial C Preprocessor](http://www.muppetlabs.com/~breadbox/software/cppp.html)

Instructions:
 - Copy the main Windows SDK folders into the same directory as the script.
 - Run the file.

The script will output copies of every header file, marked with a '.out' extension.
These copies will be partially preprocessed so that C2Nim can (usually) read the files without trouble.