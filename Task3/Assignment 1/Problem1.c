#include<stdio.h>

float addition(float * num1, float * num2){
    float res;
    res = *num1 + *num2;

    return res;
}

float subtraction(float * num1, float * num2){
    float res;
    res = *num1 - *num2;

    return res;
}

float multiplication(float * num1, float * num2){
    float res;
    res = (*num1) * (*num2);

    return res;
}

float division(float * num1, float * num2){
    float res;
    res = (*num1) / (*num2);

    return res;
}

int main(){
    printf("Enter 1 for Addition.\n"
           "Enter 2 for Subtraction.\n"
           "Enter 3 for Multiplication.\n"
           "Enrer 4 for Divition.\n");

    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);

    float num1, num2;
    printf("Enter the first number: ");
    scanf("%f", &num1);

    printf("Enter the second number: ");
    scanf("%f", &num2);

    float (*operation) (float *, float *);

    float result;

    switch (choice)
    {
    case 1 :
        operation = addition;
        result = operation(&num1, &num2);
        printf("Result of Addition: %.2f", result);
        break;

    case 2 :
        operation = subtraction;
        result = operation(&num1, &num2);
        printf("Result of Subtraction: %.2f", result);
        break;

    case 3 :
        operation = multiplication;
        result = operation(&num1, &num2);
        printf("Result of Multiplication: %.2f", result);
        break;

    case 4 :
        operation = division;
        result = operation(&num1, &num2);
        printf("Result of Division: %.2f", result);
        break;
    
    default:
        break;
    }

}