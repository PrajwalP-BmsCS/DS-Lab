#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int val;
    struct Node *prev;
    struct Node *next;
}Node;

Node *head=NULL;

void insert(){
    printf("Enter value : ");
    Node *ptr=(Node*)malloc(sizeof(Node));
    int num;
    scanf("%d",&num);
    ptr->val=num;
    ptr->next=head;
    ptr->prev=NULL;
    if (head != NULL) {
        head->prev = ptr;
    }
    head=ptr;
} 

void delete(){
    printf("Enter node to delete: ");
    int loc,len=1;
    scanf("%d",&loc);
    Node *ptr=head,*ptr2,*ptr3;
    while(ptr->next!=NULL){
        len++;
        ptr=ptr->next;
    }
    if(loc>len){
        printf("Delete index out of bounds %d\n",len);
        return;
    }
    if(loc==0){
        printf("Deleted element: %d\n",head->val);
        ptr=head;
        head=head->next;
        free(ptr);
        return;
    }
    if(loc==len){
        ptr = head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        printf("Deleted element: %d\n", ptr->val);
        ptr->prev->next = NULL;
        free(ptr);
        return;
    }
    ptr=head;
    for(int i=0;i<loc-1;i++){
        ptr2=ptr;
        ptr=ptr->next;
    }
    printf("Deleted element: %d\n",ptr->val);
    ptr2->next=ptr->next;
    ptr->next->prev=ptr2;
    free(ptr);
}

void display(){
    Node *ptr=head;
    while(ptr!=NULL){
        printf("%d->",ptr->val);
        ptr=ptr->next;
    }
    printf("NULL\n");
}

void main(){
   int choice;
    printf("1. To insert into left of Doubly Linked List\n");
    printf("2. To Delete from any point of Doubly Linked List\n");
    printf("Enter choice: ");
    while (1) {
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            default:
                printf("Exiting the program");
                return;
        }
        printf("Enter choice: ");
    }
}
