#include<stdio.h>
void swap(int *a, int *b);
void main(){
    int a,b;
    printf("Enter a and b:\n");
    scanf("%d %d",&a,&b);
    swap(&a,&b);
    printf("After swapping a=%d and b=%d",a,b);
}
void swap(int *a, int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
