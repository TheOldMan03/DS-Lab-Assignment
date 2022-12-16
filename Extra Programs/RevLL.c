#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    int Index;
    struct Node* next;
};

struct Node* head=NULL;

int count=0;

void CreateNode(int elem){ //Adding from the front

    struct Node* newNode=malloc(sizeof(struct Node));
    struct Node* temp;

    if (head==NULL){
        head=newNode;

        head->data=elem;
        head->Index=count;
        head->next=NULL;

        temp=newNode;

        count++;

    }

    else{
        temp->next=newNode; //Pointing to the previous node and updating the address bit

        temp=newNode;
        temp->data=elem;
        temp->Index=count;
        temp->next=NULL;

        count++;
    }
}

void Display(){
    struct Node* ptr;
    ptr=head;

    if (head==NULL){
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

void ReverseLL(){

    struct Node* temp1=NULL;
    struct Node* temp2;

    if (head==NULL){
        printf("The list is empty\n");
    }

    else{

        while(temp2!=NULL){

            temp2=head->next; //The next Element
            head->next=temp1; //Updating the link part of the previous element

            temp1=head;
            head=temp2;
        }
    }   
}