#include <stdio.h>
#include <stdlib.h>
#include "MessageBase.pb-c.h"

typedef Base base_msg_t;

void* pack(size_t *osize);
void unpack(void *buff, size_t* size);

int main (int argc, const char * argv[]) {
  size_t size;
  void *buff = pack(&size);
  if (buff) {
      unpack(buff, &size);

      free(buff);
      buff = NULL;
  }

  return 0;
}

void* pack(size_t *size) {
  void *buff = NULL;
  *size = 0;

  base_msg_t *msg = malloc(sizeof(base_msg_t));
  if (msg) {
      base__init(msg);

      //..........................................
      msg->a = 11;
      msg->has_b = 1;
      msg->b = 99;

      printf("packed a:%d\n", msg->a);
      printf("packed b:%d\n", msg->b);
      //..........................................

      size_t packed_size = base__get_packed_size(msg);
      if (packed_size) {
        buff = malloc(packed_size);
        if (buff) {
          base__pack(msg, buff);
          *size = packed_size;
          printf("Buffer has been successfully packed\n");
        } else {
          printf("Failed to allocate memory for outgoing buffer\n");
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

void unpack(void *buff, size_t* size) {
  if (buff) {
    base_msg_t *msg;
    msg = base__unpack(NULL, *size, buff);

    //..........................................
    printf("unpacked a:%d\n", msg->a);
    if (msg->has_b) {
      printf("unpacked b:%d\n", msg->b);
    }
    //..........................................

    base__free_unpacked(msg, NULL);
  }
  else{
    printf("Unpack buffer is null\n");
  }
}