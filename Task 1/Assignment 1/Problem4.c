#include<stdio.h>

int summation(int* ptr1, int* ptr2){
    int sum;
    sum = *ptr1 + *ptr2;

    return sum;
}

int main(){
    int x, y;
    printf("Enter two numbers: ");
    scanf("%d %d", &x, &y);

    int sum = summation(&x, &y);
    printf("The summation is: %d", sum);

    return 0;
}
