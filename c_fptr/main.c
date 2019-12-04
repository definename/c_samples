#include <stdio.h>
#include <string.h>

typedef void (*message_t)(void);

void hello(void) {
  printf("Hello\n");
}

void goodbye(void) {
  printf("Goodbye\n");
}

void call_hello_or_goodbye(message_t m) {
  m();
}

int main (int argc, const char * argv[]) {
  // .......................................
  message_t mobj;

  mobj = hello;
  mobj();

  mobj = goodbye;
  mobj();

  // .......................................
  void* m_ptr = hello;
  ((message_t)m_ptr)();

  // .......................................
  call_hello_or_goodbye(hello);
  call_hello_or_goodbye(goodbye);

  return 0;
}
