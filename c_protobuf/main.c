#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "MessageBase.pb-c.h"

typedef Base base_msg_t;
typedef Sub1 sub1_msg_t;

base_msg_t* build_base(const int32_t a, const int32_t b, void* sub1_msg, size_t sub1_size) {
  base_msg_t *msg = malloc(sizeof(base_msg_t));
  if (msg) {
      base__init(msg);
      msg->base_a = a;

      msg->has_base_b = true;
      msg->base_b = b;

      if (sub1_msg) {
        msg->has_base_c = true;
        msg->base_c.data = sub1_msg;
        msg->base_c.len = sub1_size;
      }
  }
  return msg;
}

void* pack_base(base_msg_t* base_msg, size_t* size) {
  void *buff = NULL;
  *size = 0;

  size_t packed_size = base__get_packed_size(base_msg);
  if (packed_size) {
    buff = malloc(packed_size);
    if (buff) {
      base__pack(base_msg, buff);
      *size = packed_size;
    }
  }
  return buff;
}

sub1_msg_t* build_sub1_msg(const int32_t sub_a) {
  sub1_msg_t *sub1_msg = malloc(sizeof(sub1_msg_t));
  if (sub1_msg) {
    sub1__init(sub1_msg);

    sub1_msg->has_sub_a = true;
    sub1_msg->sub_a = sub_a;
  }
  return sub1_msg;
}

void* pack_sub1_msg(sub1_msg_t* sub1_msg, size_t *size) {
  void *buff = NULL;
  *size = 0;

  size_t packed_size = sub1__get_packed_size(sub1_msg);
  if (packed_size) {
    buff = malloc(packed_size);
    if (buff) {
      sub1__pack(sub1_msg, buff);
      *size = packed_size;
    }
  }
  return buff;
}

base_msg_t *unpack_base(const size_t size, void *buff) {
  base_msg_t *base_msg = NULL;
  if (buff) {
    base_msg = base__unpack(NULL, size, buff);
  }
  return base_msg;
}

sub1_msg_t *unpack_sub1_msg(const size_t size, void *buff) {
  sub1_msg_t *sub1_msg = NULL;
  if (buff) {
    sub1_msg = sub1__unpack(NULL, size, buff);
  }
  return sub1_msg;
}

void base_dump(const base_msg_t *base_msg) {
  if (base_msg) {
    printf("base a:%d\n", base_msg->base_a);
    if (base_msg->has_base_b) {
      printf("base b:%d\n", base_msg->base_b);
    }
  }
}

void sub1_dump(const sub1_msg_t *sub1_msg) {
  if (sub1_msg) {
    if (sub1_msg->has_sub_a) {
      printf("sub a:%d\n", sub1_msg->sub_a);
    }
  }
}

void test_pack_unpack();

int main (int argc, const char * argv[]) {
  test_pack_unpack();
  return 0;
}

void test_pack_unpack() {
  int count = 100;
  while (count)
  {
    sub1_msg_t* sub1_msg_ = build_sub1_msg(0);
    size_t sub1_size;
    void *sub1_buff = pack_sub1_msg(sub1_msg_, &sub1_size);
    sub1__free_unpacked(sub1_msg_, NULL);

    base_msg_t *base_msg_ = build_base(1, 2, sub1_buff, sub1_size);

    size_t base_size;
    void* base_buff = pack_base(base_msg_, &base_size);
    base__free_unpacked(base_msg_, NULL);

    base_msg_t *_base_msg = unpack_base(base_size, base_buff);
    sub1_msg_t *_sub1_msg = unpack_sub1_msg(_base_msg->base_c.len, _base_msg->base_c.data);

    sub1_dump(_sub1_msg);
    base_dump(_base_msg);

    sub1__free_unpacked(_sub1_msg, NULL);
    base__free_unpacked(_base_msg, NULL);

    free(base_buff);
    base_buff = NULL;

    count--;
  }
}