#include<stdio.h>
#define size 10
int HT[size];

void hash(int a[]){
    for(int i=0;i<10;i++){
            HT[i]=-1;
    }
    int num,key;
    for(int i=0;i<10;i++){
        num=a[i];
        key=num%size;
        if(HT[key]==-1){
            HT[key]=a[i];
        }
        else{
            while(HT[key]!=-1){
                key=(key+1)%size;
            }
            HT[key]=a[i];
        }
    }
}

void search(int num){
    int key=num%size;
    if(HT[key]==num){
        printf("%d is at %d",num,key);
    }
    else{
        while(HT[key]!=num){
                key=(key+1)%size;
            }
            printf("%d is at index %d in HashTable",num,key);
    }
}
void main(){
    int data[10]={13,34,69,78,15,69,63,47,74,11};
    hash(data);
    int num;
    printf("Enter number to be searched: ");
    scanf("%d",&num);
    search(num);
}
