#include<stdio.h>
#include<stdlib.h>

#define use_asc

int* Asc_func(int* size){

    //int* arr = (int*)malloc(100 * sizeof(int));
    static int arr[100];
    int n = 0;

    printf("Enter numbers (enter -1 to stop): ");
    while(1) {
        int num;
        scanf("%d", &num);
        if(num == -1) break;
        arr[n] = num;
        n++;
        if(n >= 100) break;
    }

    for (int i = 0; i < n-1; i++) {     
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    *size = n;

    return arr;

}

int* Desc_func(int* size){

    //int* arr = (int*)malloc(100 * sizeof(int));
    static int arr[100];
    int n = 0;

    printf("Enter numbers (enter -1 to stop): ");
    while(1) {
        int num;
        scanf("%d", &num);
        if(num == -1) break;
        arr[n] = num;
        n++;
        if(n >= 100) break;
    }

    for (int i = 0; i < n-1; i++) {     
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] < arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    *size = n; // as the size i calculated it in this function is local so i need to pass it to the main too

    return arr;

}

/*
after searching, i found that it's not possible to return a local array
as they are automatically deallocated when the function returns.
there were two solutions for that first to 1.Dynamically allocate the array on the heap
and second 2.Use a static local array.
*/

int main(){
    int n;
    int* arr;
    #ifdef use_asc
        arr = Asc_func(&n);
    #else
        arr = Desc_func(&n);
    #endif
    
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    //free(arr);

    return 0;
}
