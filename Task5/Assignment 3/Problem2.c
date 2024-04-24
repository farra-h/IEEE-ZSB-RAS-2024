#include<stdio.h>

#define add(num1, num2) num1 + num2
#define subtract(num1, num2) num1 - num2
#define addition

int main(){
    int num1, num2, result;

    scanf("%d%d", &num1, &num2);

    #ifdef addition
        result = add(num1, num2);

    #else
        result = subtract(num1, num2);

    #endif

    printf("The result is: %d\n", result);

    return 0;
}