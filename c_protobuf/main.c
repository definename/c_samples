#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "MessageBase.pb-c.h"

typedef Base base_msg_t;
typedef Sub1 sub1_msg_t;

void* pack_base(const int32_t a, const int32_t b, size_t *size);
void* pack_sub1_msg(const int32_t val, size_t *size);

void unpack_base(size_t* size, void *buff);
void unpack_sub1_msg(size_t* size, void *buff);

int main (int argc, const char * argv[]) {
  size_t size;
  void *buff = pack_base(111, 222, &size);
  if (buff) {
      unpack_base(&size, buff);

      free(buff);
      buff = NULL;
  }

  return 0;
}

void* pack_base(const int32_t a, const int32_t b, size_t *size) {
  void *buff = NULL;
  *size = 0;

  base_msg_t *msg = malloc(sizeof(base_msg_t));
  if (msg) {
      base__init(msg);

      //..........................................
      msg->base_a = a;
      msg->has_base_b = true;
      msg->base_b = b;

      printf("packed base a:%d\n", msg->base_a);
      printf("packed base b:%d\n", msg->base_b);

      size_t sub1_size;
      void *sub1_buff = pack_sub1_msg(333, &sub1_size);
      if (sub1_buff) {
        msg->has_base_c = true;
        msg->base_c.data = sub1_buff;
        msg->base_c.len = sub1_size;
      }
      //..........................................

      size_t packed_size = base__get_packed_size(msg);
      if (packed_size) {
        buff = malloc(packed_size);
        if (buff) {
          base__pack(msg, buff);
          *size = packed_size;
          printf("Base has been successfully packed\n");
        } else {
          printf("Failed to allocate memory for base buffer\n");
        }
      } else {
        printf("Failed to retrieve required packed size\n");
      }

      base__free_unpacked(msg, NULL);
  } else {
    printf("Failed to allocate protocol message\n");
  }
  return buff;
}

void* pack_sub1_msg(const int32_t sub_a, size_t *size) {
  void *buff = NULL;
  *size = 0;

  sub1_msg_t *sub_msg = malloc(sizeof(sub1_msg_t));
  if (sub_msg) {
    sub1__init(sub_msg);

    //..........................................
    sub_msg->has_sub_a = true;
    sub_msg->sub_a = sub_a;
    printf("packed sub a:%d\n", sub_msg->sub_a);
    //..........................................
  
    size_t packed_size = sub1__get_packed_size(sub_msg);
    if (packed_size) {
      buff = malloc(packed_size);
      if (buff) {
        sub1__pack(sub_msg, buff);
        *size = packed_size;
        printf("Sub1 has been successfully packed\n");
      } else {
        printf("Failed to allocate memory for sub1 buffer\n");
      }
    } else {
      printf("Failed to retrieve required packed size\n");
    }

    sub1__free_unpacked(sub_msg, NULL);
  } else {
    printf("Failed to allocate protocol message\n");
  }

  return buff;
}

void unpack_base(size_t* size, void *buff) {
  if (buff) {
    base_msg_t *base_msg;
    base_msg = base__unpack(NULL, *size, buff);

    //..........................................
    printf("unpacked base a:%d\n", base_msg->base_a);
    if (base_msg->has_base_b) {
      printf("unpacked base b:%d\n", base_msg->base_b);
    }
    if (base_msg->has_base_c) {
      unpack_sub1_msg(&base_msg->base_c.len, base_msg->base_c.data);
    }
    //..........................................

    base__free_unpacked(base_msg, NULL);
  }
  else{
    printf("Base buff is null\n");
  }
}

void unpack_sub1_msg(size_t* size, void *buff) {
  if (buff) {
    sub1_msg_t *sub1_msg;
    sub1_msg = sub1__unpack(NULL, *size, buff);

    //..........................................
    if (sub1_msg->has_sub_a) {
      printf("unpacked sub a:%d\n", sub1_msg->sub_a);
    }
    //..........................................

    sub1__free_unpacked(sub1_msg, NULL);
  }
  else{
    printf("Sub1 buff is null\n");
  }
}