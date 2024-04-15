#include<stdio.h>

#define addition(num1, num2) num1 + num2
#define subtraction(num1, num2) num1 - num2
#define multiplication(num1, num2) num1 * num2
#define divition(num1, num2) num1 / num2

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

    float result;

    switch (choice)
    {
    case 1 :
        result = addition(num1, num2);
        printf("Result of Addition: %.2f", result);
        break;

    case 2 :
        result = subtraction(num1, num2);
        printf("Result of Subtraction: %.2f", result);
        break;

    case 3 :
        result = multiplication(num1, num2);
        printf("Result of Multiplication: %.2f", result);
        break;

    case 4 :
        result = divition(num1, num2);
        printf("Result of Division: %.2f", result);
        break;
    
    default:
        break;
    }
    
}