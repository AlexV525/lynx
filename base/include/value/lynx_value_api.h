// Copyright 2025 The Lynx Authors. All rights reserved.
// Licensed under the Apache License Version 2.0 that can be found in the
// LICENSE file in the root directory of this source tree.

#ifndef BASE_INCLUDE_VALUE_LYNX_VALUE_API_H_
#define BASE_INCLUDE_VALUE_LYNX_VALUE_API_H_

#include "base/include/value/lynx_value_types.h"

struct lynx_api_env__ {
  lynx_state state;
  lynx_api_context ctx;
  lynx_api_runtime rt;

  // type
  lynx_status (*lynx_value_typeof)(lynx_api_env env, lynx_value value,
                                   lynx_value_type* result);

  lynx_status (*lynx_get_undefined)(lynx_api_env env, lynx_value* result);
  lynx_status (*lynx_get_null)(lynx_api_env env, lynx_value* result);
  lynx_status (*lynx_get_boolean)(lynx_api_env env, bool value,
                                  lynx_value* result);

  // creator
  lynx_status (*lynx_create_double)(lynx_api_env env, double value,
                                    lynx_value* result);
  lynx_status (*lynx_create_int32)(lynx_api_env env, int32_t value,
                                   lynx_value* result);
  lynx_status (*lynx_create_uint32)(lynx_api_env env, uint32_t value,
                                    lynx_value* result);
  lynx_status (*lynx_create_int64)(lynx_api_env env, int64_t value,
                                   lynx_value* result);
  lynx_status (*lynx_create_uint64)(lynx_api_env env, uint64_t value,
                                    lynx_value* result);
  lynx_status (*lynx_create_string_utf8)(lynx_api_env env, const char* str,
                                         size_t length, lynx_value* result);
  lynx_status (*lynx_create_array)(lynx_api_env env, lynx_value* result);
  lynx_status (*lynx_create_map)(lynx_api_env env, lynx_value* result);
  lynx_status (*lynx_create_arraybuffer)(lynx_api_env env, size_t byte_length,
                                         void** data, lynx_value* result);
  lynx_status (*lynx_create_function)(lynx_api_env env, const char* utf8_name,
                                      size_t length, lynx_callback callback,
                                      void* data, lynx_value* result);

  // getter
  lynx_status (*lynx_get_value_bool)(lynx_api_env env, lynx_value value,
                                     bool* result);
  lynx_status (*lynx_get_value_double)(lynx_api_env env, lynx_value value,
                                       double* result);
  lynx_status (*lynx_get_value_int32)(lynx_api_env env, lynx_value value,
                                      int32_t* result);
  lynx_status (*lynx_get_value_uint32)(lynx_api_env env, lynx_value value,
                                       uint32_t* result);
  lynx_status (*lynx_get_value_int64)(lynx_api_env env, lynx_value value,
                                      int64_t* result);
  lynx_status (*lynx_get_value_uint64)(lynx_api_env env, lynx_value value,
                                       uint64_t* result);
  lynx_status (*lynx_get_value_number)(lynx_api_env env, lynx_value value,
                                       double* result);
  lynx_status (*lynx_get_value_external)(lynx_api_env env, lynx_value value,
                                         void** result);
  // If buf is nullptr, the *result will be the length of arraybuffer value.
  // Otherwise, the *result will be the minimum of bufsize and length of
  // arraybuffer value
  lynx_status (*lynx_get_value_string_utf8)(lynx_api_env env, lynx_value value,
                                            char* buf, size_t bufsize,
                                            size_t* result);
  lynx_status (*lynx_get_last_error_info)(
      lynx_api_env env, const lynx_extended_error_info** result);

  // array
  lynx_status (*lynx_value_is_array)(lynx_api_env env, lynx_value value,
                                     bool* result);
  lynx_status (*lynx_get_array_length)(lynx_api_env env, lynx_value value,
                                       uint32_t* result);
  lynx_status (*lynx_set_element)(lynx_api_env env, lynx_value object,
                                  uint32_t index, lynx_value value);
  lynx_status (*lynx_has_element)(lynx_api_env env, lynx_value object,
                                  uint32_t index, bool* result);
  lynx_status (*lynx_get_element)(lynx_api_env env, lynx_value object,
                                  uint32_t index, lynx_value* result);
  lynx_status (*lynx_delete_element)(lynx_api_env env, lynx_value object,
                                     uint32_t index, bool* result);

  // map
  lynx_status (*lynx_get_property_names)(lynx_api_env env,
                                         const lynx_value object,
                                         lynx_value* result);
  lynx_status (*lynx_set_named_property)(lynx_api_env env, lynx_value object,
                                         const char* utf8name,
                                         lynx_value value);
  lynx_status (*lynx_has_named_property)(lynx_api_env env, lynx_value object,
                                         const char* utf8name, bool* result);
  lynx_status (*lynx_get_named_property)(lynx_api_env env, lynx_value object,
                                         const char* utf8name,
                                         lynx_value* result);
  lynx_status (*lynx_delete_named_property)(lynx_api_env env, lynx_value object,
                                            const char* name);

  // arraybuffer
  lynx_status (*lynx_value_is_arraybuffer)(lynx_api_env env, lynx_value value,
                                           bool* result);
  lynx_status (*lynx_get_arraybuffer_info)(lynx_api_env env,
                                           lynx_value arraybuffer, void** data,
                                           size_t* byte_length);

  // function
  lynx_status (*lynx_call_function)(lynx_api_env env, lynx_value recv,
                                    lynx_value func, size_t argc,
                                    const lynx_value* argv, lynx_value* result);
  lynx_status (*lynx_get_callback_info)(lynx_api_env env,
                                        const lynx_callback_info info,
                                        size_t* argc, lynx_value* argv,
                                        lynx_value* this_arg, void** data);

  // instance data
  lynx_status (*lynx_set_instance_data)(lynx_api_env env, uint64_t key,
                                        void* data, lynx_finalizer finalizer,
                                        void* finalize_hint);
  lynx_status (*lynx_get_instance_data)(lynx_api_env env, uint64_t key,
                                        void** result);

  // equals
  lynx_status (*lynx_equals)(lynx_api_env env, lynx_value lhs, lynx_value rhs,
                             bool* result);

  // reference
  lynx_status (*lynx_create_reference)(lynx_api_env env, lynx_value value,
                                       uint32_t initial_refcount,
                                       lynx_value_ref* result);
  lynx_status (*lynx_delete_reference)(lynx_api_env env, lynx_value_ref ref);
  lynx_status (*lynx_get_reference_value)(lynx_api_env env, lynx_value_ref ref,
                                          lynx_value* result);

  // handle scope
  lynx_status (*lynx_open_handle_scope)(lynx_api_env env,
                                        lynx_handle_scope* result);
  lynx_status (*lynx_close_handle_scope)(lynx_api_env env,
                                         lynx_handle_scope scope);

  // finalizer
  lynx_status (*lynx_add_finalizer)(lynx_api_env env, lynx_value value,
                                    void* finalize_data,
                                    lynx_finalizer finalizer,
                                    void* finalize_hint);

  // cleanup hook
  lynx_status (*lynx_add_env_cleanup_hook)(lynx_api_env env,
                                           lynx_cleanup_hook func, void* arg);
  lynx_status (*lynx_remove_env_cleanup_hook)(lynx_api_env env,
                                              lynx_cleanup_hook func,
                                              void* arg);

  // others
  lynx_status (*lynx_get_length)(lynx_api_env env, lynx_value value,
                                 uint32_t* result);

  lynx_status (*lynx_deep_copy_value)(lynx_api_env env, lynx_value src,
                                      lynx_value* result);

  lynx_status (*lynx_has_string_ref)(lynx_api_env env, lynx_value value,
                                     bool* result);
  // Get a string object raw pointer.
  lynx_status (*lynx_get_value_string_ref)(lynx_api_env env, lynx_value value,
                                           void** result);
};

#endif  // BASE_INCLUDE_VALUE_LYNX_VALUE_API_H_
