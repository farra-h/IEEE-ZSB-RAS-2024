#include<stdio.h>
#include<complex.h>

typedef struct complexnum{
    double complex number;
}num;

void sum(num num1, num num2){
    num sum;
    sum.number = num1.number + num2.number;
    printf("The sum is: %.2f + %.2fi\n", creal(sum.number), cimag(sum.number));
}
int main(){
    double n1[2], n2[2];
    num num1, num2;

    printf("Enter the real and imaginary parts of the first number:\n");
    scanf("%lf%lf", &n1[0], &n1[1]);

    printf("Enter the real and imaginary parts of the second number:\n");
    scanf("%lf%lf", &n2[0], &n2[1]);

    num1.number = n1[0] + n1[1] * I;
    num2.number = n2[0] + n2[1] * I;

    sum(num1, num2);
    
    return 0;
}