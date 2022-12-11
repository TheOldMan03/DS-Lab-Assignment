#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    int Index;
    struct Node* next;
};

struct Node* head=NULL;
struct Node* tail=NULL;

int count=0;

void CreateNode(int elem){ //Adding from the front

    struct Node* newNode=malloc(sizeof(struct Node));

    if (head==NULL){
        head=newNode;

        head->data=elem;
        head->Index=count;
        head->next=NULL;

        tail=newNode;

        count++;

    }

    else{
        tail->next=newNode; //Pointing to the previous node and updating the address bit

        tail=newNode;
        tail->data=elem;
        tail->Index=count;
        tail->next=NULL;

        count++;
    }
}

void DeleteAlternate(){

    struct Node* current;
    struct Node* previous;
    struct Node* temp;

    if (head==NULL){ //No element 
        printf("List Empty\n");
    }

    else if (head->next==NULL){ //Only 1 element in the list
        free(head);
        head=NULL;

        printf("\nLast element deleted!");
    }

    else{

        previous=head;
        current=head->next;

        while(current!=NULL){

            if ((current->Index)%2!=0){

                previous->next=current->next;
                temp=current;
                current=current->next;

                free(temp);
                temp=NULL;
            }

            else{
                previous=previous->next;
                current=current->next;
            }

        }

        current=head;
        count=0;

        while(current!=NULL){
            current->Index=count;
            count++;
            current=current->next;
        }

        tail=current;
        printf("Alternate Elements are successfully deleted! ");
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


int main(){
    int choice;
    int elem;

    do{
        printf("\n1.Insert element");
        printf("\n2.Delete Alternate Element");
        printf("\n3.Display");
        printf("\n4.Exit\n");

        printf("Enter Choice: ");
        scanf("%d",&choice);

        switch(choice){

            case 1:
                printf("\nEnter value: ");
                scanf("%d",&elem);
                CreateNode(elem);
                break;
            
            case 2:
                DeleteAlternate();
                break;
            
            case 3:
                Display();
                break;
            
            case 4:
                printf("");
                break;
            
            default:
                printf("Invalid Choice!");

        }
    } while(choice!=4);

    return 0;
}