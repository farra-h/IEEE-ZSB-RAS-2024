#include<stdio.h>

int main(){
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements of the array: ");
    int max_element = 0;
    for(int i=0; i<size; i++){
        scanf("%d", &arr[i]);
        if(arr[i] > max_element)
            max_element = arr[i];
    }

    int seen[max_element + 1];
    for(int i=0; i<=max_element; i++){
        seen[i] = 0;
    }

    for(int i=0; i<size; i++){
        seen[arr[i]]++;
    }

    printf("The unique elements in the array are: ");
    for(int i=0; i<=max_element; i++){
        if(seen[i] == 1)
            printf("%d ", i);
    }

    return 0;
}
