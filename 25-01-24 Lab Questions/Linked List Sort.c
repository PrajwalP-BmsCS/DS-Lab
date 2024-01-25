#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node *head;
void create(){

    int A[]={2,1,3,5,4,8,6,7,0,9};
    printf("Elements of Linked List A:  ");
    for(int i=0;i<10;i++){
        printf("%d ",A[i]);
    }
    struct node *t, *last;
    head = (struct node*)malloc(sizeof(struct node));
    head->data = A[0];
    head->next = NULL;
    last = head;
    for(int i=1; i<10; i++){
        t = (struct node*)malloc(sizeof(struct node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

struct node* sort(struct node *head) {
    struct node *ptr1,*ptr2;
    ptr1=head;
    int temp,count=1;
    while(ptr1->next!=NULL){
        count++;
        ptr1=ptr1->next;
    }
    ptr1=head;
    while(--count){
        ptr1=head;
        while(ptr1->next!=NULL){
            ptr2=ptr1;
            ptr1=ptr1->next;
            if(ptr1->data<ptr2->data){
                temp=ptr2->data;
                ptr2->data=ptr1->data;
                ptr1->data=temp;
            }
        }
    }
    return head;
}

void main(){
    create();
    head = sort(head);
    struct node* p = head;
    printf("\nSorted Linked List A:  ");
    while(p!=NULL){
            printf("%d ",p->data);
            p = p->next;
    }
}
