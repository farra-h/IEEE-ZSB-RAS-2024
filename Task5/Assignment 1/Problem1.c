#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct student_info{
    int roll_number : 4;
    int age : 8;
    int marks : 3;
    char address[40];
    char name[40];
};

void info(struct student_info student[15]){
    for(int i=0; i<15; i++){
    printf("Roll Number: %d\n", student[i].roll_number);
    printf("Name: %s\n", student[i].name);
    printf("Age: %d\n", student[i].age);
    printf("Address: %s\n", student[i].address);
    printf("Marks: %d\n", student[i].marks);
    printf("\n");
   }
}

int main(){
    srand(time(NULL));
    struct student_info student[15];

    for(int i=0; i<15; i++){
    student[i].roll_number = i+1;
    sprintf(student[i].name, "student %d", i + 1);
    student[i].age = 20 + i;
    sprintf(student[i].address, "Address %d", i + 1);
    student[i].marks = rand() % 21; 
   }

   info(student);
   printf("The total size of the struct: %lu bytes\n", sizeof(struct student_info));

    return 0;
}

/*
When the processor deals with each member of the struct, it will access the memory location of that member and retrieve the value.
For bit fields, the processor will use bitwise operations to extract the correct bits.
*/
/*
after searching it says that in C bit fields can only be declared as int, unsigned int, or _Bool.
Therefore, we cannot apply the bit field concept to strings such as name and address. 
*/