#include <stdio.h>

void test_bases(void);
void test_sscanf(void);

int main (int argc, const char *argv[]){
  test_sscanf();
  test_bases();
  return 0;
}

void test_bases(void){
  int x = 1000;
  printf("%d octal:%o hex:%x\n", x, x, x);
  printf("%d octal:%#o hex:%#x hex:%#X\n", x, x, x, x);
}

void test_sscanf(void){
  char input[] = "11";
  int output;
  sscanf(input, "%d", &output);
  printf("%d\n", output);
}