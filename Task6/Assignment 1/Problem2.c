#include<stdio.h>
#include<stdlib.h>

int main(){
    int n1 = 4, n2 = 3, n3 = 2;
    int* ptr1;
    int* ptr2;
    int* ptr3;

    ptr1 = (int*) malloc(n1 * sizeof(int));
    if( ptr1 == NULL){
        printf("Memory can't be allocated in ptr1\n");
        return 0;
    }
    printf("Memory has been successfully allocated using malloc in ptr1\n");


    ptr2 = (int*) calloc(n2, sizeof(int));
    if( ptr2 == NULL){
        printf("Memory can't be allocated in ptr2\n");
        return 0;
    }
    printf("Memory has been successfully allocated using calloc in ptr2\n");


    ptr3 = (int*) malloc(n3 * sizeof(int));
    if( ptr3 == NULL){
        printf("Memory can't be allocated in ptr3\n");
        return 0;
    }
    printf("Memory has been successfully allocated using malloc in ptr3\n");

    
    free(ptr1);
    printf("Memory has been successfully freed in ptr1\n");

    int n4 = 10;
    int* ptr4;

    ptr4 = (int*) malloc(n4 * sizeof(int));
    if( ptr4 == NULL){
        printf("Memory can't be allocated in ptr4\n");
        return 0;
    }
    printf("Memory has been successfully allocated using malloc in ptr4\n");

    free(ptr2);
    free(ptr3);
    free(ptr4);
    return 0;
}

/*
if i had a limited memory space the allocation would fail and the malloc function would return NULL
and the massege "Memory can't be allocated" would be printed,
and this is because malloc requires a single contiguous block of memory to allocate the requested space 

*/
