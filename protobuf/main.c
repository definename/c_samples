#include <stdio.h>
#include <stdlib.h>
#include "AMessage.pb-c.h"

void* pack(AMessage *msg, size_t *size);
void unpack(void *buff, size_t* osize);

int main (int argc, const char * argv[]){
  AMessage *msg = NULL;
  msg = malloc(sizeof(*msg));
  amessage__init(msg);

  //.......................................
  void *buff = NULL;
  size_t size;
  buff = pack(msg, &size);
  unpack(buff, &size);
  //.......................................
  
  amessage__free_unpacked(msg, NULL);
  if (buff){
    printf("Free buffer\n");
    free(buff);
  }
  else{
    printf("Invalid buffer pointer\n");
  }

  return 0;
}

void* pack(AMessage *msg, size_t *osize){
  void *buff = NULL;
  if (msg){

      //..........................................
      msg->a = 11;
      printf("packed a:%d\n", msg->a);
      msg->has_b = 1;
      msg->b = 99;
      printf("packed b:%d\n", msg->b);
      //..........................................

    size_t packed_size;
    packed_size = amessage__get_packed_size(msg);
    *osize = packed_size;
    if (packed_size){
      buff = malloc(packed_size);
      if (buff){
        printf("Buffer has been successfully packed\n");
        amessage__pack(msg, buff);
      }
      else{
        printf("Failed to allocate memory for outgoing buffer\n");
      }
    }
    else{
      printf("Failed to retrieve required packed size\n");
    }
  }
  else{
    printf("Failed to pack message, invalid pointer was given\n");
  }
  return buff;
}

void unpack(void *buff, size_t* size){
  if (buff){
    AMessage *msg;
    msg = amessage__unpack(NULL, *size, buff);

    //..........................................
    printf("unpacked a:%d\n", msg->a);
    if (msg->has_b) {
      printf("unpacked b:%d\n", msg->b);
    }
    //..........................................

    amessage__free_unpacked(msg, NULL);
  }
  else{
    printf("Failed to unpack message, invalid pointer was given\n");
  }
}