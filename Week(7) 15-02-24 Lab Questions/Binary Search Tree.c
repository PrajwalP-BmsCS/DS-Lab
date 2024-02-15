#include<stdio.h>
#include<stdlib.h>

struct Tree{
    int val;
    struct Tree *left;
    struct Tree *right;
};

struct Tree *root=NULL;

struct Tree* newNode(int a){
    struct Tree *ptr=(struct Tree*)malloc(sizeof(struct Tree));
        ptr->val=a;
        ptr->left=ptr->right=NULL;
        return ptr;
}

struct Tree* insert(struct Tree *ptr, int a){
    if(ptr==NULL){
        return newNode(a);
    }
    else if(ptr->val<a){
        ptr->right=insert(ptr->right,a);
    }
    else if(ptr->val>a){
        ptr->left=insert(ptr->left,a);
    }
}

void inOrder(struct Tree *ptr){
    if (ptr != NULL) {
        inOrder(ptr->left);
        printf(" %d ", ptr->val);
        inOrder(ptr->right);
    }
}

void PreOrder(struct Tree *ptr){
    if (ptr != NULL) {
        printf(" %d ", ptr->val);
        PreOrder(ptr->left);
        PreOrder(ptr->right);
    }
}

void PostOrder(struct Tree *ptr){
    if (ptr != NULL) {
        PostOrder(ptr->left);
        PostOrder(ptr->right);
        printf(" %d ", ptr->val);
    }
}

void main(){
    int arr[]={8,5,6,1,2,3,7,4,9,0};
    printf("Array to sort: %d ",arr[0]);
    root=insert(root,arr[0]);

    for(int i=1;i<10;i++){
        printf("%d ",arr[i]);
        insert(root,arr[i]);
    }printf("\nInOrder representation: ");
    inOrder(root);
    printf("\nPreOrder representation: ");
    PreOrder(root);
    printf("\nPostOrder representation: ");
    PostOrder(root);
}
