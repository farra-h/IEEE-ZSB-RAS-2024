#include<stdio.h>

#define usingMacros(type) ((char *)(&type + 1) - (char *)(&type)) // locate the next location of type and the curren one then by subtracting them i get the size of type

/*
after searching i found that it’s not possible to create an inline function in C that mimics the exact functionality of the sizeof operator
i tried different ways but it always leads to a specific size based on the datatype i pass to the function like here :

static inline size_t usingInline(const void *type) {
    return (size_t)(((char *)((char *)type + 1)) - (char *)type);
}  // it always returns 1 because of char 

i tried this too:

static inline size_t usingInline(const void *var) {
    return sizeof(*(int *)var);
}  // but this also depends on this part (int *) so it returns 4

*/

int main() {
    int x;

    printf("Size of int using macros: %d\n", usingMacros(x));
    //printf("Size of int using inline: %zu\n", usingInline(&x)); // %zu format specifier for size_t
    
    double y;

    printf("Size of double using macros: %d\n", usingMacros(y));
    //printf("Size of double using inline: %zu\n", usingInline(&y));
    
    
    return 0;
}
/*
Macros are processed by the preprocessor before the program is compiled, so it's fast but hard to debug

inline keyword is used to suggest to the compiler that it should attempt to generate code (inline the function) in such a way that the function’s code gets inserted into the caller’s code stream.
This can, in some cases, improve performance by avoiding function call overhead, especially for small functions.

regular sizeof() operator is a part of the C language itself. It’s evaluated at compile time, which means it doesn’t have any runtime overhead
>> It’s the best option
*/