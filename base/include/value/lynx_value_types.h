// Copyright 2025 The Lynx Authors. All rights reserved.
// Licensed under the Apache License Version 2.0 that can be found in the
// LICENSE file in the root directory of this source tree.

#ifndef BASE_INCLUDE_VALUE_LYNX_VALUE_TYPES_H_
#define BASE_INCLUDE_VALUE_LYNX_VALUE_TYPES_H_

#include <stddef.h>
#include <stdint.h>

#define FOR_EACH_LYNX_VALUE_CALL(V) \
  V(value_typeof)                   \
  V(get_undefined)                  \
  V(get_null)                       \
  V(get_boolean)                    \
  V(create_double)                  \
  V(create_int32)                   \
  V(create_uint32)                  \
  V(create_int64)                   \
  V(create_uint64)                  \
  V(create_string_utf8)             \
  V(create_array)                   \
  V(create_map)                     \
  V(create_arraybuffer)             \
  V(create_function)                \
  V(get_value_bool)                 \
  V(get_value_double)               \
  V(get_value_int32)                \
  V(get_value_uint32)               \
  V(get_value_int64)                \
  V(get_value_uint64)               \
  V(get_value_number)               \
  V(get_value_external)             \
  V(get_value_string_utf8)          \
  V(get_last_error_info)            \
  V(value_is_array)                 \
  V(get_array_length)               \
  V(set_element)                    \
  V(has_element)                    \
  V(get_element)                    \
  V(delete_element)                 \
  V(get_property_names)             \
  V(set_named_property)             \
  V(has_named_property)             \
  V(get_named_property)             \
  V(delete_named_property)          \
  V(value_is_arraybuffer)           \
  V(get_arraybuffer_info)           \
  V(call_function)                  \
  V(get_callback_info)              \
  V(set_instance_data)              \
  V(get_instance_data)              \
  V(equals)                         \
  V(create_reference)               \
  V(delete_reference)               \
  V(get_reference_value)            \
  V(open_handle_scope)              \
  V(close_handle_scope)             \
  V(add_env_cleanup_hook)           \
  V(remove_env_cleanup_hook)        \
  V(get_length)                     \
  V(deep_copy_value)                \
  V(has_string_ref)                 \
  V(get_value_string_ref)

#ifndef LYNX_VALUE_COMPILE_UNIT
#define LYNX_VALUE_COMPILE_UNIT
#endif

#define LYNX_VALUE_OPAQUE_STRUCT__2(name, unit) lynx_api_##name##__##unit
#define LYNX_VALUE_OPAQUE_STRUCT__1(name, unit) \
  LYNX_VALUE_OPAQUE_STRUCT__2(name, unit)
#define LYNX_VALUE_OPAQUE_STRUCT(name) \
  LYNX_VALUE_OPAQUE_STRUCT__1(name, LYNX_VALUE_COMPILE_UNIT)

typedef struct lynx_value_ptr__* lynx_value_ptr;
typedef struct lynx_api_env__* lynx_api_env;

typedef struct LYNX_VALUE_OPAQUE_STRUCT(context) * lynx_api_context;
typedef struct LYNX_VALUE_OPAQUE_STRUCT(runtime) * lynx_api_runtime;
typedef struct LYNX_VALUE_OPAQUE_STRUCT(ref) * lynx_value_ref;
typedef struct LYNX_VALUE_OPAQUE_STRUCT(handle_scope) * lynx_handle_scope;
typedef struct LYNX_VALUE_OPAQUE_STRUCT(callback_info) * lynx_callback_info;

typedef void (*lynx_finalizer)(lynx_api_env env, void* finalize_data,
                               void* finalize_hint);
typedef void (*lynx_cleanup_hook)(void* data);

typedef enum {
  lynx_value_null,
  lynx_value_undefined,
  lynx_value_bool,
  lynx_value_double,
  lynx_value_int32,
  lynx_value_uint32,
  lynx_value_int64,
  lynx_value_uint64,
  lynx_value_nan,
  lynx_value_string,
  lynx_value_array,
  lynx_value_map,
  lynx_value_arraybuffer,
  lynx_value_function,
  lynx_value_object,
  lynx_value_external,  // external raw pointer
  lynx_value_extended,
} lynx_value_type;

typedef enum {
  lynx_ok,
  lynx_failed,
  lynx_invalid_arg,
  lynx_not_support,
  lynx_boolean_expected,
  lynx_double_expected,
  lynx_int32_expected,
  lynx_uint32_expected,
  lynx_int64_expected,
  lynx_uint64_expected,
  lynx_string_expected,
  lynx_array_expected,
  lynx_map_expected,
  lynx_external_expected,
  lynx_arraybuffer_expected,
  lynx_function_expected,
  lynx_index_out_of_range,
  lynx_handle_scope_mismatch,
} lynx_status;

struct lynx_value {
  union {
    bool val_bool;
    double val_double;
    int32_t val_int32;
    uint32_t val_uint32;
    int64_t val_int64;
    uint64_t val_uint64;
    lynx_value_ptr val_ptr;
  };

  lynx_value_type type = lynx_value_null;
  int64_t tag = 0;
};

typedef lynx_value (*lynx_callback)(lynx_api_env env,
                                    const lynx_callback_info info);

typedef struct {
  const char* error_message;
  void* engine_reserved;
  uint32_t engine_error_code;
  lynx_status error_code;
} lynx_extended_error_info;

#endif  // BASE_INCLUDE_VALUE_LYNX_VALUE_TYPES_H_
