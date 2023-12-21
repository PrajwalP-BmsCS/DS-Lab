#include<stdio.h>
#include<stdlib.h>
#define max 10
void push(int a);
int pop();
void display(int a[]);
int num[max],top =-1;

void main(){
    int n,a;
    printf("Enter\n1 to push into stack\n2 to pop stack\n3 to display stack\n");
    scanf("%d",&n);
    while(n!=3){
        switch(n){
        case 1: printf("Enter element to push\n");
                scanf("%d",&a);
                push(a);
                break;
        case 2: a=pop();
                printf("Popped element: %d\n",a);
                break;
        default: printf("Wrong input");
        }
        scanf("%d",&n);
    }
    if(n==3){
        display(num);
    }
}
void push(int a){
    if(top>max-1){
        printf("Stack overflow");
        exit(0);
    }
    else{
        ++top;
        num[top]=a;
    }
}

int pop(){
    if(top==-1){
        printf("Stack underflow:");
        exit(0);
    }
    else{
        return num[top];
        --top;

    }
}

void display(int a[]){
    printf("Elements of stack: ");
    for(int i=0;i<top;i++){
        printf(" %d ",num[i]);
    }
}

