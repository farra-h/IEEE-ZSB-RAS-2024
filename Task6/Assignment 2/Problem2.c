#include<stdio.h>
#include<string.h>

void uniqueChar(char string[], int size){

    int unique[256] = {0};

    for(int i = 0; i < size; i++)
        unique[string[i]]++;

    printf("Unique characters: ");
    for(int i = 0; i < size; i++){
        if(unique[string[i]] == 1){
           printf("%c ", string[i]);
           unique[string[i]] = 0; // So it doesn't print the same character again
        }
    }
    printf("\n");
}

int main(){
    char string[1000];

    do {  // to at least do one loop
        printf("Enter a string [Enter !! to stop the program]: ");
        fgets(string, sizeof(string), stdin); // Read the string

        string[strcspn(string, "\n")] = '\0'; /* this line to replace the newline from the fgets function to a null char
          to ensure that the string doesn’t include the newline character when it’s printed or used  */

        if(strcmp(string, "!!") != 0) {
            int size = strlen(string);
            uniqueChar(string, size);
        }
    } while(strcmp(string, "!!") != 0);

    return 0;
}