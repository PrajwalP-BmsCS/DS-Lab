#include<stdio.h>
#include<stdlib.h>
struct Node{
    int val;
    struct Node *next;
}Node;

struct Node *top=NULL;

int pop(){
    if(top==NULL){
        printf("Empty stack");
    }
    struct Node *ptr=top;
    top=top->next;
    int num= ptr->val;
    free(ptr);
    printf("Popped element: %d\n",num);
}

void push() {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    int new_data;
    printf("Enter element to add to stack: ");
    scanf("%d", &new_data);
    temp->val = new_data;
    temp->next = top;
    top=temp;
}

void display() {
    struct Node* temp1 = top;
    while (temp1 != NULL) {
        printf("%d\n", temp1->val);
        temp1 = temp1->next;
    }
}

int main(){
   int choice;
    printf("1. To Push into stack\n");
    printf("2. To Pop from stack\n");
    printf("3. Display\n");
    printf("4. Exit\n");
    printf("Enter choice: ");
    while (1) {
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            default:
                printf("Exiting the program");
                return 0;
        }
        printf("Enter choice: ");
    }
}
