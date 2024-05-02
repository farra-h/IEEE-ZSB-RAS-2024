#include<stdio.h>

int main(){
    int seconds, minutes, hours;

    printf("Enter the time in the format [hh:mm:ss]: ");
    scanf("%d%d%d", &hours, &minutes, &seconds);

    int total = hours*3600 + minutes*60 + seconds; // storing in a single integer

    hours = total/3600;
    total %= 3600;
    minutes = total/60;
    seconds = total%60;

    printf("The time is: %02d:%02d:%02d", hours, minutes, seconds); // to match the format 
    //%02d means that an integer is printed as at least 2 digits, and if the integer has fewer than 2 digits, it is prefixed with zeros
    // this touch from chatgpt ^^
    return 0;
}