#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head=NULL;

void display();
void create();
void fdelete();
void ldelete();
void idelete();


int main() {
    create();
    int choice;
    display();
    while (1) {
        printf("1. Delete first element\n");
        printf("2. Delete last element\n");
        printf("3. Delete specific position\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                fdelete();
                break;
            case 2:
                ldelete();
                break;
            case 3:
                idelete();
                break;
            case 4:
                display();
                break;
            default:
                printf("Exiting the program");
                return 0;
        }
    }
}


void fdelete(){
    if(head==NULL){
        printf("Empty list");
    }
    Node *ptr=head;
    head=head->next;
    free(ptr);
}

void ldelete(){
    if(head==NULL){
        printf("Empty list");
    }
    Node *ptr=head;
    Node *ptr1=head;
    while(ptr->next!=NULL){
        ptr1=ptr;
        ptr=ptr->next;
    }
    ptr1->next=NULL;
    free(ptr);
}

void idelete(){
    printf("Enter position of deletion:");
    int pos;
    scanf("%d",&pos);
     if(head==NULL){
        printf("Empty list");
    }
    Node *ptr=head;
    Node *ptr1=head;
    pos=pos-1;
    while(pos--){
        ptr1=ptr;
        ptr=ptr->next;
    }
    ptr1->next=ptr->next;
    free(ptr);
}

void display() {
    Node* temp1 = head;
    while (temp1 != NULL) {
        printf("%d -> ", temp1->data);
        temp1 = temp1->next;
    }
    printf("NULL\n");
}

void create(){
    int A[]={0,1,2,3,4,5,6,7,8,9};
    struct Node *t, *last;
    head = (struct Node*)malloc(sizeof(struct Node));
    head->data = A[0];
    head->next = NULL;
    last = head;
    for(int i=1; i<10; i++){
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }

}
