#include<stdio.h>
#include<string.h>
#define size 100

int main(){
    char str1[size];
    char str2[size];

    printf("Enter the stirng you want to be copied: ");
    fgets(str1, size, stdin);

    strcpy(str2, str1);
    printf("The copied string is: %s", str2);

    return 0;
}