#include <stdio.h>
#include <stdint.h>

int main(int argc, char* argv[]) {
    char arr[] = "0123456789abcd";
    uint32_t c = 0x55555555;
    *((uint32_t*)arr + 1) = c;

    printf("%s\n", arr);
    return 0;
}