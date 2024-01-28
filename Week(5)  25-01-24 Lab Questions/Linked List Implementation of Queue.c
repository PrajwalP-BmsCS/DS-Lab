#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int val;
    struct Node *next;
}Node;

Node *head=NULL;

void enqueue(){
    Node *ptr=(Node*)malloc(sizeof(Node));
    printf("Enter element to enqueue: ");
    int num;
    scanf("%d",&num);
    ptr->val=num;
    if(head==NULL){
        head=ptr; 
        ptr->next=NULL;
    }
    else{
        Node *ptr2=head;
        while(ptr2->next!=NULL){
            ptr2=ptr2->next;
        }
        ptr2->next=ptr;
    }
}

void display(){
    Node *ptr=head;
    while(ptr!=NULL){
        printf("%d ",ptr->val);
        ptr=ptr->next;
    }
    printf("\n");
}

void dequeue(){
    Node *ptr=head;
    int num=ptr->val;
    head=head->next;
    free(ptr);
    printf("Dequeued element: %d\n",num);
}

int main(){
    int choice;
    printf("1. To Enqueue into Queue\n");
    printf("2. To Dequeue from Queue\n");
    printf("3. Display\n");
    printf("4. Exit\n");
    printf("Enter choice: ");
    while (1) {
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
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
