#include<stdio.h>
#define size 100

int main(){
    char str[size];

    printf("Enter a stirng: ");
    fgets(str, size, stdin);

    for(int i=0; str[i]!='\0'; i++){
        if(str[i] != ' ')
            printf("%c ", str[i]);
    }

    return 0;
}