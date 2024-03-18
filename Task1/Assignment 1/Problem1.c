#include<stdio.h>

int main(){
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size], seen[size];
    int sum = 0;

    printf("Enter the elements of the array: ");
    for(int i=0; i<size; i++){
        scanf("%d", &arr[i]);
        seen[i] = 0;
    }

    for(int i=0; i<size; i++){
        seen[arr[i]]++;
    }

    for(int i=0; i<size; i++){
        if(seen[i] > 1)
            sum++;
    }

    printf("The total number of duplicate elements in the array is: %d", sum);

    return 0;
}
