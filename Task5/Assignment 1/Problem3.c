#include <stdio.h>

typedef char CHAR8;
typedef int INT32;
typedef float FLOAT32;
typedef double DOUBLE64;
typedef long LONG32;
typedef short SHORT16;

int main() {
    printf("Size of CHAR8: %lu bytes\n", sizeof(CHAR8));
    printf("Size of INT32: %lu bytes\n", sizeof(INT32));
    printf("Size of FLOAT32: %lu bytes\n", sizeof(FLOAT32));
    printf("Size of DOUBLE64: %lu bytes\n", sizeof(DOUBLE64));
    printf("Size of LONG32: %lu bytes\n", sizeof(LONG32));
    printf("Size of SHORT16: %lu bytes\n", sizeof(SHORT16));

    return 0;
}
