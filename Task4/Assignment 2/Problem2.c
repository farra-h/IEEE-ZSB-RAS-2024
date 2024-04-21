#include<stdio.h>

struct info
{
    char name[40];
    int age;
};


int main(){
    struct info object = {"object name", 20};
    struct info *ptr = &object;

    printf("The name of the object: %s\n", (*ptr).name);
    printf("The age of the object: %d\n", (*ptr).age);

    return 0;
}