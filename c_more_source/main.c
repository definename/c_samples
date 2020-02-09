#include <stdio.h>
#include <string.h>

// We need to add this prototype or move into util.h file and include it.
void do_util(void);

int main (const int argc, const char * argv[]) {
  do_util();
  return 0;
}
