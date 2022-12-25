#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node* prev;
    int data;
    struct Node* next;
};

struct Node* head=NULL;
struct Node* tail=NULL;

int Count(){
    if (head==NULL){
        return 0;
    }

    else{
        struct Node* ptr=head;
        int count=1;

        while(ptr!=NULL){
            ptr=ptr->next;
            count++;
        }

        return count;
    }
}


void IsEmpty(int elem){

    struct Node* newNode=malloc(sizeof(struct Node));

    head=newNode;

    head->data=elem;
    head->prev=NULL;
    head->next=NULL;

    tail=newNode;

}

void InsertionEnd(int elem){

    struct Node* newNode=malloc(sizeof(struct Node));

    if (head==NULL){
        IsEmpty(elem);
    }

    else{

        newNode->prev=tail;
        newNode->data=elem;
        newNode->next=NULL;

        tail=newNode;
    }
}

void InsertAfter(int elem,int next_elem){

    struct Node* newNode=malloc(sizeof(struct Node));
    struct Node* ptr;

    if (head==NULL){
        IsEmpty(elem);
    }

    else{

        int flag=0;
        ptr=head;

        while(ptr!=NULL){
            if(ptr->data==next_elem){
                flag=1;
                break;
            }
            ptr=ptr->next;
        }

        if(flag==1){

            newNode->next=ptr->next;
            newNode->prev=ptr;
            newNode->data=elem;

            ptr->next=newNode;
        }

        else{
            printf("\nThe given element does not exist!");
        }
    }

}

void InsertBefore(int elem,int prev_elem){

    struct Node* newNode=malloc(sizeof(struct Node));
    struct Node* ptr;

    if(head==NULL){
        IsEmpty(elem);
    }

    else{
        int flag=0;
        ptr=head;

        while(ptr!=head){
            if(ptr->data==prev_elem){
                flag=1;
                break;
            }
            ptr=ptr->next;
        }

        if(flag==1){
            newNode->prev=ptr->prev;
            newNode->data=elem;
            newNode->next=ptr;

            ptr->prev=newNode;
        }

        else{
            printf("\nThe given element does not exist!");
        }
    
    }

}

void InsertAnyPosition(int elem,int pos){

    struct Node* newNode=malloc(sizeof(struct Node));
    struct Node* ptr;

    int Max_elem=Count();


    if (head==NULL){
        IsEmpty(elem);
    }

    else{
        if (pos==1){//1st Position

            newNode->data=elem;
            newNode->next=head;
            newNode->prev=NULL;

            head=newNode;
        }

        else if (pos==Max_elem){
            newNode->data=elem;
            newNode->prev=tail;
            newNode->next=NULL;

            tail=newNode;
        }

        else if(pos>Max_elem){
            printf("\nList out of range");
        }

        else{
            ptr=head;
            int count=1;

            while(count!=pos){
                ptr=ptr->next;
                count++;
            }

            newNode->next=ptr;
            newNode->prev=ptr->prev;
            newNode->data=elem;

            ptr->prev=newNode;
            (newNode->prev)->next=newNode;
            
        }
    }
}

void Delete(struct Node** ptr){

    if((*ptr)->prev==NULL){ //if the node to be deleted is the 1st node

        head=head->next; //Changing the head value
        (*ptr)->next=NULL;
        free((*ptr));
        *ptr=NULL;
    }

    else if((*ptr)->next==NULL){//if the node to be deleted is the last node

        tail=tail->prev;
        (*ptr)->prev=NULL;
        free(*ptr);
        *ptr=NULL;

    }

    else{

        ((*ptr)->prev)->next=(*ptr)->next;
        ((*ptr)->next)->prev=(*ptr)->prev; 
        //chance for segmentation fault if node selected is 1st or last

        (*ptr)->next=NULL;
        (*ptr)->prev=NULL;

        free(*ptr);
        *ptr=NULL;
    }
}


void DeleteNode(int del_elem){

    if (head==NULL){
        printf("\nLL is Empty! ");
    }

    else{
        struct Node* temp;
        struct Node* ptr;

        ptr=head;
        int flag=0;

        while(ptr!=NULL){
            if(ptr->data==del_elem){
                flag=1;
                break;
            }
            ptr=ptr->next;
        }

        Delete(&ptr);
    }
}

void DeletePos(int pos){
    if (head==NULL){
        printf("\nLL is empty");
    }

    else{
        struct Node* ptr;
        int Max_Terms=Count();

        if (pos==1){
            ptr=head;
            head=head->next;
            ptr->next=NULL;

            free(ptr);
            ptr=NULL;

        }

        else if (pos==Max_Terms){
            ptr=tail;
            tail=tail->prev;
            ptr->prev=NULL;

            free(ptr);
            ptr=NULL;
        }

        else{
            int count=1;
            ptr=head;

            while(count!=pos){
                ptr=ptr->next;
            }

            (ptr->prev)->next=ptr->next;
            (ptr->next)->prev=ptr->prev; 
            //chance for segmentation fault if node selected is 1st or last

            ptr->next=NULL;
            ptr->prev=NULL;

            free(ptr);
            ptr=NULL;
        }
    }
}

void DeleteSmallest(){
    if (head==NULL){
        printf("\nThe LL is emtpy");
    }

    else{

        int smallest=head->data;

        struct Node* smallptr=head->next;
        struct Node* ptr=head;

        while(ptr!=NULL){
            if (smallest<(ptr->data) && ptr!=head){ //2nd condition is to avoid checking the 1st elemenet again
                smallest=ptr->data;
                smallptr=ptr;

                ptr=ptr->next;
            }

            ptr=ptr->next;
        }

        Delete(&ptr);
    }
}

//include the main function