#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;   
};

struct Node* head = NULL; // global so i could use it

void insert(){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter node data: ");
    scanf("%d", &(temp->data));
    temp->next = head;
    head = temp;
}

void delete(){
    if (head == NULL) {
        printf("List is empty, cannot delete.\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
}

void print(){
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("List is: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    char c;

    printf("Enter + to add a node\n"
           "Enter - to delete a node\n"
           "Enter p to print the list\n"
           "Enter x to Exit\n\n");

    do
    {
        printf("Enter your choice: ");
        scanf(" %c", &c); // added a space before %c to consume any newline character left in the input buffer

        switch (c)
        {
        case '+':
            insert();
            break;

        case '-':
            delete();
            break;
        
        case 'p':
            print();
            break;

        default:
            break;
        }

    } while (c != 'x');
    
    return 0;
}
