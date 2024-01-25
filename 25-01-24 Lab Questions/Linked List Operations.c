#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node *head,*headB;
void createA(){

    int A[]={2,1,3,5,4,8,6,7,0,9};
    printf("Elements of Linked List A:  ");
    for(int i=0;i<10;i++){
        printf("%d->",A[i]);
    }
    printf("NULL");
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

void createB(){

    int B[]={11,13,12,10,14};
    printf("\nElements of Linked List B:  ");
    for(int i=0;i<5;i++){
        printf("%d->",B[i]);
    }
    printf("NULL");
    struct node *t, *last;
    headB = (struct node*)malloc(sizeof(struct node));
    headB->data = B[0];
    headB->next = NULL;
    last = headB;
    for(int i=1; i<5; i++){
        t = (struct node*)malloc(sizeof(struct node));
        t->data = B[i];
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

struct node* concat(struct node *head, struct node *headB){
    struct node *ptr=head;
    while(ptr->next!=NULL){
                ptr=ptr->next;
    }
    ptr->next=headB;
    return head;
}
struct node* reverse(struct node *head){
    struct node *pre, *cur, *after;
    pre = NULL;
    after = cur = head;
    while(after != NULL)
    {
        after = after->next;
        cur->next = pre;
        pre = cur;
        cur = after;
    }
    head = pre;
    return head;
}
void main(){
    createA();
    createB();
    head = sort(head);
    struct node *p=head;
    printf("\nSorted Linked List A:  ");
    while(p!=NULL){
            printf("%d->",p->data);
            p = p->next;
    }
    printf("NULL");
    headB = sort(headB);
    p = headB;
    printf("\nSorted Linked List B:  ");
    while(p!=NULL){
            printf("%d->",p->data);
            p = p->next;
    }
    printf("NULL");
    p=concat(head,headB);
    printf("\nConcatenation of Sorted A and B:  ");
    while(p!=NULL){
            printf("%d->",p->data);
            p = p->next;
    }
    printf("NULL\n");
    p=reverse(head);
    printf("Reverse of A Concat B:  ");
    while(p!=NULL){
            printf("%d->",p->data);
            p = p->next;
    }
     printf("NULL");
}
