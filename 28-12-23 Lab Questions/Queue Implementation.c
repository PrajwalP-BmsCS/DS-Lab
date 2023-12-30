#include<stdio.h>
#include<stdlib.h>
#define max 20
int queue[max];
int front=-1, rear=-1;

void enqueue(int a);
int dequeue();
void display();

void main(){
    int n,m;
    printf("Enter\n1.To insert into queue\n2.To remove from queue\n3.To display queue:\n");
    scanf("%d",&n);
    while(n!=3){
        switch(n){
            case 1: printf("Enter element to enter into queue:");
                    scanf("%d",&m);
                    enqueue(m);
                    break;
                    
            case 2: m=dequeue();
                    printf("Removed element is %d\n",m);
                    break;
        
            default: printf("Invalid input");
        }
        scanf("%d",&n);
        printf("\n");
    }
    if(n==3){
            display();
        }
}

void enqueue(int a){
    if(rear==max-1){
        printf("Queue overflow");
        
    }
    rear+=1;
    queue[rear]=a;
}

int dequeue(){
    if(rear==-1 || front==rear){
        printf("Queue underflow");
        exit(0); 
    }
    else{
        front+=1;
        return queue[front];
    }
}

void display(){
    
    printf("Queue:\n");
    for(int i=front+1;i<=rear;i++){
        printf("%d\t",queue[i]);
        }
    
}
