/* Generated by the protocol buffer compiler.  DO NOT EDIT! */
/* Generated from: MessageBase.proto */

#ifndef PROTOBUF_C_MessageBase_2eproto__INCLUDED
#define PROTOBUF_C_MessageBase_2eproto__INCLUDED

#include <protobuf-c/protobuf-c.h>

PROTOBUF_C__BEGIN_DECLS

#if PROTOBUF_C_VERSION_NUMBER < 1000000
# error This file was generated by a newer version of protoc-c which is incompatible with your libprotobuf-c headers. Please update your headers.
#elif 1003002 < PROTOBUF_C_MIN_COMPILER_VERSION
# error This file was generated by an older version of protoc-c which is incompatible with your libprotobuf-c headers. Please regenerate this file with a newer version of protoc-c.
#endif


typedef struct _Sub1 Sub1;
typedef struct _Base Base;


/* --- enums --- */


/* --- messages --- */

struct  _Sub1
{
  ProtobufCMessage base;
  protobuf_c_boolean has_b_a;
  int32_t b_a;
};
#define SUB1__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&sub1__descriptor) \
    , 0, 0 }


struct  _Base
{
  ProtobufCMessage base;
  int32_t a;
  protobuf_c_boolean has_b;
  int32_t b;
  protobuf_c_boolean has_c;
  ProtobufCBinaryData c;
};
#define BASE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&base__descriptor) \
    , 0, 0, 0, 0, {0,NULL} }


/* Sub1 methods */
void   sub1__init
                     (Sub1         *message);
size_t sub1__get_packed_size
                     (const Sub1   *message);
size_t sub1__pack
                     (const Sub1   *message,
                      uint8_t             *out);
size_t sub1__pack_to_buffer
                     (const Sub1   *message,
                      ProtobufCBuffer     *buffer);
Sub1 *
       sub1__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   sub1__free_unpacked
                     (Sub1 *message,
                      ProtobufCAllocator *allocator);
/* Base methods */
void   base__init
                     (Base         *message);
size_t base__get_packed_size
                     (const Base   *message);
size_t base__pack
                     (const Base   *message,
                      uint8_t             *out);
size_t base__pack_to_buffer
                     (const Base   *message,
                      ProtobufCBuffer     *buffer);
Base *
       base__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   base__free_unpacked
                     (Base *message,
                      ProtobufCAllocator *allocator);
/* --- per-message closures --- */

typedef void (*Sub1_Closure)
                 (const Sub1 *message,
                  void *closure_data);
typedef void (*Base_Closure)
                 (const Base *message,
                  void *closure_data);

/* --- services --- */


/* --- descriptors --- */

extern const ProtobufCMessageDescriptor sub1__descriptor;
extern const ProtobufCMessageDescriptor base__descriptor;

PROTOBUF_C__END_DECLS


#endif  /* PROTOBUF_C_MessageBase_2eproto__INCLUDED */
