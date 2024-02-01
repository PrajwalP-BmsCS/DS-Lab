#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int val;
    struct Node *prev;
    struct Node *next;
}Node;

Node *head=NULL;

void insert(){
    int num,pos;
    printf("Enter value : ");
    scanf("%d",&num);
    printf("Enter node to insert left of: ");
    scanf("%d",&pos);

    Node *ptr=(Node*)malloc(sizeof(Node));
    ptr->val=num;

    if(pos==0){
    ptr->next=head;
    ptr->prev=NULL;
        if (head != NULL){
            head->prev = ptr;
        }
    head=ptr;

    }
    Node *ptr1=head;

    if(pos!=0){
        for(int i=0;i<pos;i++){
            ptr1=ptr1->next;
        }
        ptr->next=ptr1;
        ptr->prev=ptr1->prev;
        ptr1->prev->next=ptr;
        ptr1->prev=ptr;


    }
}

void delete(){
    printf("Enter value to delete: ");
    int loc=-1,len=1,val;
    scanf("%d",&val);
    Node *ptr=head,*ptr2;
    while(ptr->next!=NULL){
        len++;
        ptr=ptr->next;
    }
    ptr=head;
    for(int i=0;i<len;i++){
        if(ptr->val=val){
            loc=i;
        }
    }

    if(loc==-1){
        printf("Delete element not in list\n");
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
        printf("%d<->",ptr->val);
        ptr=ptr->next;
    }
    printf("NULL\n");
}

void main(){
   int choice;
    printf("1. To insert into left of Doubly Linked List\n");
    printf("2. To Delete from any value of Doubly Linked List\n");
    printf("3. To display list");
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
