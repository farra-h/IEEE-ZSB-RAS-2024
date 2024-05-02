#include<stdio.h>

int maxFreq(char arr[], int size){

    int freq[256] = {0};
    int max = -1;

    for(int i = 0; i < size; i++) // i=0
        freq[arr[i]]++;  // freq[arr[0]]  freq[first char ascii] ++ 0 >> 1

    for(int i = 0; i < size; i++){
        if(max < freq[arr[i]]){
            max = freq[arr[i]];
        }
    }

    return max;
}

int main(){

    int size;
    printf("Enter the maximum length for the name: ");
    scanf("%d", &size);

    char arr[size+1];

    getchar(); // consume the newline character (\n) that is left in the input buffer after scanf, without it it didn't give me the output i want

    printf("Enter the name: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%c", &arr[i]);
    }
    
    arr[size] = '\0';

    int max = maxFreq(arr, size);

    printf("The name is: %s\nThe frequency of the most repeated character is: %d", arr, max);

    return 0;
}