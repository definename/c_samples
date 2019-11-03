#include <stdio.h>
#include <inttypes.h>

void test_bases(void);
void test_sscanf(void);
void test_portable_type(void);

int main (int argc, const char *argv[]){
  test_sscanf();
  test_bases();
  test_portable_type();
  return 0;
}

void test_portable_type(void){
  int32_t i = 9;
  printf("PRId32:%" PRId32 "\n", i);
  int_least32_t ii = 99;
  printf("PRIdLEAST32:%" PRIdLEAST32 "\n", ii);
  int_fast32_t iii = 999;
  printf("PRIdFAST32:%" PRIdFAST32 "\n", iii);
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