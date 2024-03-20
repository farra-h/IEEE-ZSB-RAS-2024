#include<stdio.h>

int main(){
    int x = 1, y = 2, z = 3;
    int *p = &x, *q = &y, *r = &z;

    printf("x: %d\ny: %d\nz: %d\n", x, y, z);
    printf("p: %d\nq: %d\nr: %d\n", p, q, r);
    printf("*p: %d\n*q: %d\n*r: %d\n", *p, *q, *r);

    printf("Swaping pointers:\n");
    r = p; p = q; q = r;

    printf("x: %d\ny: %d\nz: %d\n", x, y, z);
    printf("p: %d\nq: %d\nr: %d\n", p, q, r);
    printf("*p: %d\n*q: %d\n*r: %d\n", *p, *q, *r);

    return 0;
}
