#include<stdio.h>

int maxFreq(char arr[], int size){

    int freq[256] = {0};
    int max = -1;
    //char result;

    for(int i = 0; i < size; i++)
        freq[arr[i]]++;

    for(int i = 0; i < size; i++){
        if(max < freq[arr[i]]){
            max = freq[arr[i]];
            //result = arr[i];
        }
    }

    return max;
}

int main(){

    int size;
    printf("Enter the maximum length for the name: ");
    scanf("%d", &size);

    char arr[size+1];

    getchar();

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