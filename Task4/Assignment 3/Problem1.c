#include <stdio.h>
#include <string.h>

struct test1 {
    int id;
    char name[50];
    char class_id;
};

struct test2 {
    char name[50];
    int id;
    char class_id;
};

int main() {
    printf("Size of test1: %lu\n", sizeof(struct test1));
    printf("Size of test2: %lu\n", sizeof(struct test2));
    return 0;
}
/*
Yes there is a difference between the two inputs as,
the order of fields in a struct can affect the total size of the struct due to padding.
*/