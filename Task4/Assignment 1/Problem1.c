#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct student_info
{
    int rollNumber;
    char name[40];
    int age;
    char address[40];
    int marks;
};

int main(){
   srand(time(NULL));
   struct student_info student[15];

   for(int i=0; i<15; i++){
    student[i].rollNumber = i+1;
    sprintf(student[i].name, "student %d", i + 1);
    student[i].age = 20 + i;
    sprintf(student[i].address, "Address %d", i + 1);
    student[i].marks = rand() % 21; 
   }

   for(int i=0; i<15; i++){
    printf("Roll Number: %d\n", student[i].rollNumber);
    printf("Name: %s\n", student[i].name);
    printf("Age: %d\n", student[i].age);
    printf("Address: %s\n", student[i].address);
    printf("Marks: %d\n", student[i].marks);
    printf("\n");
   }

    return 0;
}