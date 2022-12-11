#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* headA=NULL;
struct Node* headB=NULL;

struct Node* headC=NULL;

struct Node* tailA=NULL;
struct Node* tailB=NULL;

void InsertA(int elem){ //The parameters are used to determine which Head to use

    struct Node* newNode=malloc(sizeof(struct Node));

    if (headA==NULL){
        headA=newNode;

        headA->data=elem;
        headA->next=NULL;

        tailA=newNode;
    }

    else{
        tailA->next=newNode; //Pointing to the previous node and updating the address bit

        tailA=newNode;
        tailA->data=elem;
        tailA->next=NULL;

    }
}

void InsertB(int elem){ //The parameters are used to determine which Head to use

    struct Node* newNode=malloc(sizeof(struct Node));

    if (headB==NULL){
        headB=newNode;

        headB->data=elem;
        headB->next=NULL;

        tailB=newNode;
    }

    else{
        tailB->next=newNode; //Pointing to the previous node and updating the address bit

        tailB=newNode;
        tailB->data=elem;
        tailB->next=NULL;

    }
}


void MergeSort(){

    struct Node* ptrA=headA;
    struct Node* ptrB=headB;
    struct Node* temp;

    if (headA==NULL || headB==NULL){

        printf("Either of the 2 lists are empty!\n");
    }

    else{

        while(ptrA!=NULL && ptrB!=NULL){ //Ignoring the case of same number existing in the list

            if ((ptrA->data)<(ptrB->data)){

                temp=ptrA->next;
                ptrA->next=ptrB;
                ptrA=temp;

            }

            else{
                temp=ptrB->next;
                ptrB->next=ptrA;
                ptrB=temp;
            }

        }

        if ((headA->data)<(headB->data)){
            headC=headA;
        }

        else{
            headC=headB;
        }
    }

}

void DisplayA(){

    struct Node* ptr;
    ptr=headA;

    if (headA==NULL){
        printf("List empty!\n");
    }

    else{
        printf("\n");

        while(ptr->next!=NULL){
            printf("%d->",ptr->data);
            ptr=ptr->next;
        }

        printf("%d",ptr->data);
        printf("\n");
    }
    
}

void DisplayB(){

    struct Node* ptr;
    ptr=headB;

    if (headB==NULL){
        printf("List empty!\n");
    }

    else{
        printf("\n");

        while(ptr->next!=NULL){
            printf("%d->",ptr->data);
            ptr=ptr->next;
        }

        printf("%d",ptr->data);
        printf("\n");
    }
    
}

void DisplayC(){

    struct Node* ptr;
    ptr=headC;

    if (headC==NULL){
        printf("List empty!\n");
    }

    else{
        printf("\n");

        while(ptr->next!=NULL){
            printf("%d->",ptr->data);
            ptr=ptr->next;
        }

        printf("%d",ptr->data);
        printf("\n");
    }
    
}

int main(){

    int a,b;

    printf("\nEnter the number of elements for List A: ");
    scanf("%d",&a);

    printf("\nEnter the number of elements for List B: ");
    scanf("%d",&b);

    int i,elem;


    printf("\nEnter the elements for ListA: \n");
    for(i=0;i<a;i++){
        scanf("%d",&elem);
        InsertA(elem);
    }

    printf("\nEnter the elements for ListB: \n");
    for(i=0;i<b;i++){
        scanf("%d",&elem);
        InsertB(elem);
    }

    printf("\nList A\n");
    DisplayA();
    printf("\n");

    printf("\nList B\n");
    DisplayB();

    printf("\nThe Merged List\n");
    MergeSort();
    DisplayC();

}