#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node* prev;
    int data;
    struct Node* next
};

struct Node* head=NULL;
struct Node* tail=NULL;

void IsEmpty(int elem){ //DRY---->Don't Repeat Yourself

    struct Node* newNode=malloc(sizeof(struct Node));

    head=newNode;
    tail=newNode;

    head->data=elem;
    head->next=NULL;
    head->prev=NULL;

}

void EnqueueFront(int elem){

    struct Node* newNode=malloc(sizeof(struct Node));

    if (head==NULL){ //Queue Empty
        IsEmpty(elem);
    }

    else{

        tail->next=newNode; //Updating the 'next' part of the previous Node before updating tail
        newNode->prev=tail; //Updating the 'prev' of lastest Node 

        tail=newNode; //Tail is now the new Node (No Shit Sherlock)

        tail->data=elem;
        tail->next=NULL;

    }

}

void EnqueueBack(int elem){

    struct Node* newNode=malloc(sizeof(struct Node));

    if (head==NULL){ //Queue Empty
        IsEmpty(elem);
    }

    else{
        head->prev=newNode;
        newNode->next=head;

        head=newNode;

        head->data=elem;
        head->prev=NULL;
    }

}

void DeQueue(){
    
}