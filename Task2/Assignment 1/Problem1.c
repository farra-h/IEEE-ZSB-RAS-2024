#include<stdio.h>

int main(){
    int *p1;
    char *p2;
    long long *p3;

    printf("p1 --> %d\np2 --> %c\np3 --> %lld\n", p1++, p2++, p3++);
    printf("The reason of that output is because,"
    " i'm trying to increment an uninitialized pointers that are pointing to some random memory location,"
    " and incrementing them just moves to some other random location.");

    return 0;
}