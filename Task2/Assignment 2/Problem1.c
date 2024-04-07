#include<stdio.h>

int *increment(int *value){
    (*value)++;
    return value;
}

int main(){
    int value;
    printf("Enter the number you want to increment: ");
    scanf("%d", &value);

    int *ptr;
    ptr = increment(&value);
    printf("The incremented value is: %d", *ptr);

    return 0;
}