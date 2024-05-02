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


    n1 = 3;
    ptr1 = realloc(ptr1, n1 * sizeof(int));
    if( ptr1 == NULL){
        printf("Memory can't be reallocated in ptr1\n");
        return 0;
    }
    printf("Memory has been successfully reallocated in ptr1\n");


    for(int i=0; i<n1; i++){
        *(ptr1 + i) = i;
    }
    printf("Values assigned to ptr1 are: ");
    for (int i = 0; i < n1; i++)
    {
        printf("%d ", *(ptr1 + i));
    }
    printf("\n");

    // assign values to ptr2 and ptr3 like ptr1 
    
    free(ptr1);
    free(ptr2);
    free(ptr3);

    return 0;
}
