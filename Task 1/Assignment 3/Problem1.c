#include<stdio.h>
#define size 100

int main(){
    char str[size];

    printf("Enter a stirng: ");
    fgets(str, size, stdin);
    printf("The string is: %s", str);

    return 0;
}