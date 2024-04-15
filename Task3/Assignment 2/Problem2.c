#include<stdio.h>
#define DEBUG 1

int main(){
// This is determined at compile time
// it only evaluates constant expressions and macros
#if DEBUG
    printf("Debugging is enabled.\n");
#else
    printf("Debugging is disabled.\n");
#endif

int debug = 1;
// is executed depends on the value of the debug variable at runtime
if (debug) {
    printf("Debugging is enabled.\n");
} else {
    printf("Debugging is disabled.\n");
}

    return 0;
}