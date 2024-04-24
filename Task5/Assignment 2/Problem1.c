#include<stdio.h>

enum Operation{
    add = '+',
    subtract = '-',
    multiply = '*',
    divide = '/',
    and = '&',
    or = '|',
    not = '!'
};

double calculator(double operand1, double operand2, enum Operation operation){
    switch (operation)
    {
    case add:
        return operand1 + operand2;

    case subtract:
        return operand1 - operand2;

    case multiply:
        return operand1 * operand2;

    case divide:
        if(operand2 != 0)
            return operand1 / operand2;
        else
            printf("You can't divide by zero.\n");
                return 0;

    case and:
        return (int)operand1 & (int)operand2;

    case or:
        return (int)operand1 | (int)operand2;
        
    case not:
        return !(int)operand1;
    
    default:
        break;
    }
}

int main(){

    double operand1, operand2;
    char operation;

    printf("Enter operand1, operand2 and operation: ");
    scanf("%lf %lf %c", &operand1, &operand2, &operation);

    double result = calculator(operand1, operand2, (enum Operation)operation);
    printf("The result is: %.2lf\n", result);
    printf("Size of Operation: %lu bytes\n", sizeof(enum Operation));
    /*Adding more members to the enum does not change its size.
    This is because the enum values are just symbolic constants for integer values, and the enum type itself is still represented as an integer.
    So, no matter how many members you have in the enum, its size remains the same.*/

    return 0;
}