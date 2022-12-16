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

void Insert(struct Node** head,struct Node** tail,int elem){ 

    struct Node* newNode=malloc(sizeof(struct Node));

    if (*head==NULL){
        *head=newNode;

        (*head)->data=elem;
        (*head)->next=NULL;

        (*tail)=newNode;
    }

    else{
        (*tail)->next=newNode; //Pointing to the previous node and updating the address bit

        *tail=newNode;
        (*tail)->data=elem;
        (*tail)->next=NULL;

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

void Display(struct Node** head){

    struct Node* ptr=*head;

    if (*head==NULL){
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
        Insert(&headA,&tailA,elem);
    }

    printf("\nEnter the elements for ListB: \n");
    for(i=0;i<b;i++){
        scanf("%d",&elem);
        Insert(&headB,&tailB,elem);
    }

    printf("\nList A\n");
    Display(&headA);
    printf("\n");

    printf("\nList B\n");
    Display(&headB);

    printf("\nThe Merged List\n");
    MergeSort();
    Display(&headC);

}