#include<stdio.h>
#define size 100

int main(){
    char str1[size];
    char str2[size];

    printf("Enter the first stirng: ");
    fgets(str1, size, stdin);

    printf("Enter the second stirng: ");
    fgets(str2, size, stdin);

    int flag = 1;
    for(int i=0; str1[i]!='\0'; i++){
        if(str1[i] != str2[i]){
            flag = 0;
            break;
        }
    }

    if(flag)
        printf("The two stings are equal.\n");
    else
        printf("The two stings are not equal.\n");
    
    return 0;
}