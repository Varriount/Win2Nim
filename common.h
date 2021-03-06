// Builtin defines
#undef __ATOM__
#undef __AVX__
#undef __AVX2__
#undef __CLR_VER
#undef _CONTROL_FLOW_GUARD
#undef __cplusplus_cli
#undef __cplusplus_winrt
#undef __cplusplus
#undef _CPPRTTI
#undef _CPPUNWIND
#undef __INTELLISENSE__
#undef _M_CEE
#undef _M_CEE_PURE
#undef _M_CEE_SAFE
#undef _MANAGED
#define _WIN32

// Misc
#define WINAPI __stdcall
#undef MIDL_PASS
#undef __midl
#undef _MAC
#undef USE_MIDL_SYNTAX
#define __unaligned

// basetypes.h
#define EXTERN_C extern
#define STDMETHODCALLTYPE __stdcall
#define STDMETHODVCALLTYPE __cdecl
#define STDAPICALLTYPE __stdcall
#define STDAPIVCALLTYPE __cdecl
#define STDAPI EXTERN_C HRESULT STDAPICALLTYPE
#define STDAPI_(type) EXTERN_C type STDAPICALLTYPE
#define STDMETHODIMP HRESULT STDMETHODCALLTYPE
#define STDMETHODIMP_(type) type STDMETHODCALLTYPE
#define STDAPIV EXTERN_C HRESULT STDAPIVCALLTYPE
#define STDAPIV_(type) EXTERN_C type STDAPIVCALLTYPE
#define STDMETHODIMPV HRESULT STDMETHODVCALLTYPE
#define STDMETHODIMPV_(type) type STDMETHODVCALLTYPE
#define interface struct
#define STDMETHOD(method) HRESULT (STDMETHODCALLTYPE * method)
#define STDMETHOD_(type,method) type (STDMETHODCALLTYPE * method)
#define STDMETHODV(method) HRESULT (STDMETHODVCALLTYPE * method)
#define STDMETHODV_(type,method) type (STDMETHODVCALLTYPE * method)
#define IFACEMETHOD(method) __override STDMETHOD(method)
#define IFACEMETHOD_(type,method) __override STDMETHOD_(type,method)
#define IFACEMETHODV(method) __override STDMETHODV(method)
#define IFACEMETHODV_(type,method) __override STDMETHODV_(type,method)
#define PURE
#define THIS_ INTERFACE FAR* This,
#define THIS INTERFACE FAR* This
#undef CONST_VTABLE
#define DECLARE_INTERFACE(iface) typedef interface iface { struct iface##Vtbl FAR* lpVtbl; } iface; typedef struct iface##Vtbl iface##Vtbl; struct iface##Vtbl
#define DECLARE_INTERFACE_(iface, baseiface) DECLARE_INTERFACE(iface)

// nosal2.h
#define _When_(c,a)
#define _At_(t,a)
#define _At_buffer_(t,i,c,a)
#define _Group_(a)
#define _Pre_
#define _Post_
#define _Deref_
#define _Null_
#define _Notnull_
#define _Maybenull_
#define _Const_
#define _Check_return_
#define _Must_inspect_result_
#define _Pre_satisfies_(e)
#define _Post_satisfies_(e)
#define _Writable_elements_(s)
#define _Writable_bytes_(s)
#define _Readable_elements_(s)
#define _Readable_bytes_(s)
#define _Null_terminated_
#define _NullNull_terminated_
#define _Valid_
#define _Notvalid_
#define _Success_(c)
#define _Return_type_success_(c)
#define _On_failure_(a)
#define _Always_(a)
#define _Use_decl_annotations_
#define _Pre_defensive_
#define _Post_defensive_
#define _Pre_unknown_
#define _Acquires_lock_(e)
#define _Releases_lock_(e)
#define _Requires_lock_held_(e)
#define _Requires_lock_not_held_(e)
#define _Requires_no_locks_held_
#define _Guarded_by_(e)
#define _Write_guarded_by_(e)
#define _Interlocked_
#define _Post_same_lock_(e1,e2)
#define _Benign_race_begin_
#define _Benign_race_end_
#define _No_competing_thread_
#define _No_competing_thread_begin_
#define _No_competing_thread_end_
#define _Acquires_shared_lock_(e)
#define _Releases_shared_lock_(e)
#define _Requires_shared_lock_held_(e)
#define _Acquires_exclusive_lock_(e)
#define _Releases_exclusive_lock_(e)
#define _Requires_exclusive_lock_held_(e)
#define _Has_lock_kind_(n)
#define _Create_lock_level_(n)
#define _Has_lock_level_(n)
#define _Lock_level_order_(n1,n2)
#define _Analysis_assume_lock_acquired_(e)
#define _Analysis_assume_lock_released_(e)
#define _Analysis_assume_lock_held_(e)
#define _Analysis_assume_lock_not_held_(e)
#define _Analysis_assume_same_lock_(e)
#define _In_
#define _Out_
#define _Inout_
#define _In_z_
#define _Inout_z_
#define _In_reads_(s)
#define _In_reads_bytes_(s)
#define _In_reads_z_(s)
#define _In_reads_or_z_(s)
#define _Out_writes_(s)
#define _Out_writes_bytes_(s)
#define _Out_writes_z_(s)
#define _Inout_updates_(s)
#define _Inout_updates_bytes_(s)
#define _Inout_updates_z_(s)
#define _Out_writes_to_(s,c)
#define _Out_writes_bytes_to_(s,c)
#define _Out_writes_all_(s)
#define _Out_writes_bytes_all_(s)
#define _Inout_updates_to_(s,c)
#define _Inout_updates_bytes_to_(s,c)
#define _Inout_updates_all_(s)
#define _Inout_updates_bytes_all_(s)
#define _In_reads_to_ptr_(p)
#define _In_reads_to_ptr_z_(p)
#define _Out_writes_to_ptr_(p)
#define _Out_writes_to_ptr_z_(p)
#define _In_opt_
#define _Out_opt_
#define _Inout_opt_
#define _In_opt_z_
#define _Inout_opt_z_
#define _In_reads_opt_(s)
#define _In_reads_opt_z_(s)
#define _In_reads_bytes_opt_(s)
#define _Out_writes_opt_(s)
#define _Out_writes_bytes_opt_(s)
#define _Out_writes_opt_z_(s)
#define _Inout_updates_opt_(s)
#define _Inout_updates_bytes_opt_(s)
#define _Inout_updates_opt_z_(s)
#define _Out_writes_to_opt_(s,c)
#define _Out_writes_bytes_to_opt_(s,c)
#define _Out_writes_all_opt_(s)
#define _Out_writes_bytes_all_opt_(s)
#define _Inout_updates_to_opt_(s,c)
#define _Inout_updates_bytes_to_opt_(s,c)
#define _Inout_updates_all_opt_(s)
#define _Inout_updates_bytes_all_opt_(s)
#define _In_reads_to_ptr_opt_(p)
#define _In_reads_to_ptr_opt_z_(p)
#define _Out_writes_to_ptr_opt_(p)
#define _Out_writes_to_ptr_opt_z_(p)
#define _Outptr_
#define _Outptr_opt_
#define _Outptr_result_maybenull_
#define _Outptr_opt_result_maybenull_
#define _Outptr_result_z_
#define _Outptr_opt_result_z_
#define _Outptr_result_maybenull_z_
#define _Outptr_opt_result_maybenull_z_
#define _COM_Outptr_
#define _COM_Outptr_opt_
#define _COM_Outptr_result_maybenull_
#define _COM_Outptr_opt_result_maybenull_
#define _Outptr_result_buffer_(s)
#define _Outptr_result_buffer_maybenull_(s)
#define _Outptr_result_bytebuffer_(s)
#define _Outptr_result_bytebuffer_maybenull_(s)
#define _Outptr_opt_result_buffer_(s)
#define _Outptr_opt_result_buffer_maybenull_(s)
#define _Outptr_opt_result_bytebuffer_(s)
#define _Outptr_opt_result_bytebuffer_maybenull_(s)
#define _Outptr_result_buffer_to_(s,c)
#define _Outptr_result_bytebuffer_to_(s,c)
#define _Outptr_opt_result_buffer_to_(s,c)
#define _Outptr_opt_result_bytebuffer_to_(s,c)
#define _Ret_
#define _Ret_valid_
#define _Ret_z_
#define _Ret_writes_(s)
#define _Ret_writes_bytes_(s)
#define _Ret_writes_z_(s)
#define _Ret_writes_to_(s,c)
#define _Ret_writes_bytes_to_(s,c)
#define _Ret_writes_to_ptr_(p)
#define _Ret_writes_to_ptr_z_(p)
#define _Ret_writes_maybenull_(s)
#define _Ret_writes_bytes_maybenull_(s)
#define _Ret_writes_to_maybenull_(s,c)
#define _Ret_writes_bytes_to_maybenull_(s,c)
#define _Ret_writes_maybenull_z_(s)
#define _Ret_null_
#define _Ret_notnull_
#define _Ret_maybenull_
#define _Ret_maybenull_z_
#define _Field_size_(s)
#define _Field_size_opt_(s)
#define _Field_size_bytes_(s)
#define _Field_size_bytes_opt_(s)
#define _Field_size_part_(s,c)
#define _Field_size_part_opt_(s,c)
#define _Field_size_bytes_part_(s,c)
#define _Field_size_bytes_part_opt_(s,c)
#define _Field_size_full_(s)
#define _Field_size_full_opt_(s)
#define _Field_size_bytes_full_(s)
#define _Field_size_bytes_full_opt_(s)
#define _Printf_format_string_
#define _Scanf_format_string_
#define _Scanf_s_format_string_
#define _Printf_format_string_params_(x)
#define _Scanf_format_string_params_(x)
#define _Scanf_s_format_string_params_(x)
#define _In_range_(l,h)
#define _Out_range_(l,h)
#define _Ret_range_(l,h)
#define _Deref_in_range_(l,h)
#define _Deref_out_range_(l,h)
#define _Deref_inout_range_(l,h)
#define _Field_range_(l,h)
#define _Pre_equal_to_(e)
#define _Post_equal_to_(e)
#define _Struct_size_bytes_(s)
#define _Analysis_assume_
#define _Analysis_assume_nullterminated_(s)
#define _Analysis_mode_(m)
#define _Analysis_noreturn_
#define _Raises_SEH_exception_
#define _Maybe_raises_SEH_exception_
#define _Function_class_(n)
#define _Literal_
#define _Notliteral_
#define _Enum_is_bitflag_
#define _Strict_type_match_
#define _Points_to_data_
#define _Interlocked_operand_
#define _IRQL_raises_(i)
#define _IRQL_requires_(i)
#define _IRQL_requires_max_(i)
#define _IRQL_requires_min_(i)
#define _IRQL_saves_
#define _IRQL_saves_global_(k,s)
#define _IRQL_restores_
#define _IRQL_restores_global_(k,s)
#define _IRQL_always_function_min_(i)
#define _IRQL_always_function_max_(i)
#define _IRQL_requires_same_
#define _IRQL_uses_cancel_
#define _IRQL_is_cancel_
#define _Kernel_float_saved_
#define _Kernel_float_restored_
#define _Kernel_float_used_
#define _Kernel_acquires_resource_(k)
#define _Kernel_releases_resource_(k)
#define _Kernel_requires_resource_held_(k)
#define _Kernel_requires_resource_not_held_(k)
#define _Kernel_clear_do_init_(yn)
#define _Kernel_IoGetDmaAdapter_
#define _Outref_
#define _Outref_result_maybenull_
#define _Outref_result_buffer_(s)
#define _Outref_result_bytebuffer_(s)
#define _Outref_result_buffer_to_(s,c)
#define _Outref_result_bytebuffer_to_(s,c)
#define _Outref_result_buffer_all_(s)
#define _Outref_result_bytebuffer_all_(s)
#define _Outref_result_buffer_maybenull_(s)
#define _Outref_result_bytebuffer_maybenull_(s)
#define _Outref_result_buffer_to_maybenull_(s,c)
#define _Outref_result_bytebuffer_to_maybenull_(s,c)
#define _Outref_result_buffer_all_maybenull_(s)
#define _Outref_result_bytebuffer_all_maybenull_(s)
#define _In_defensive_(a)
#define _Out_defensive_(a)
#define _Inout_defensive_(a)
#define _Outptr_result_nullonfailure_
#define _Outptr_opt_result_nullonfailure_
#define _Outref_result_nullonfailure_
#define _Result_nullonfailure_
#define _Result_zeroonfailure_
#define _Acquires_nonreentrant_lock_(e)
#define _Releases_nonreentrant_lock_(e)
#define _Function_ignore_lock_checking_(e)
#define _Analysis_suppress_lock_checking_(e)
#define _Reserved_           _Pre_equal_to_(0) _Pre_ _Null_
#define _Pre_z_              _Pre_ _Null_terminated_
#define _Post_z_             _Post_ _Null_terminated_
#define _Prepost_z_          _Pre_z_ _Post_z_
#define _Pre_null_           _Pre_ _Null_
#define _Pre_maybenull_      _Pre_ _Maybenull_
#define _Pre_notnull_        _Pre_ _Notnull_
#define _Pre_valid_          _Pre_notnull_ _Pre_ _Valid_
#define _Pre_opt_valid_      _Pre_maybenull_ _Pre_ _Valid_
#define _Post_valid_         _Post_ _Valid_
#define _Post_invalid_       _Post_ _Deref_ _Notvalid_
#define _Post_ptr_invalid_   _Post_ _Notvalid_
#define _Pre_readable_size_(s)      _Pre_ _Readable_elements_(s) _Pre_ _Valid_
#define _Pre_writable_size_(s)      _Pre_ _Writable_elements_(s)
#define _Pre_readable_byte_size_(s) _Pre_ _Readable_bytes_(s) _Pre_ _Valid_
#define _Pre_writable_byte_size_(s) _Pre_ _Writable_bytes_(s)
#define _Post_readable_size_(s)     _Post_ _Readable_elements_(s) _Post_ _Valid_
#define _Post_writable_size_(s)     _Post_ _Writable_elements_(s)
#define _Post_readable_byte_size_(s) _Post_ _Readable_bytes_(s) _Post_ _Valid_
#define _Post_writable_byte_size_(s) _Post_ _Writable_bytes_(s)