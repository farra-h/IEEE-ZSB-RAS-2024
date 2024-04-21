#include <stdio.h>
#include <string.h>

struct Date
{
    char days[3];
    char months[3];
    char year[5];
};

int main(){
    struct Date date[2];

    for (int i = 0; i < 2; i++)
    {
        printf("Enter the date number %d in the format (days-months-year) (00-00-0000): ", i+1);
        scanf("%s %s %s", date[i].days, date[i].months, date[i].year);
    }
    
    if(strcmp(date[0].days, date[1].days) == 0 && strcmp(date[0].months, date[1].months) == 0 && strcmp(date[0].year, date[1].year) == 0)
        printf("Dates are equal.\n");
    else
        printf("Dates are not equal.\n");

    return 0;
}
