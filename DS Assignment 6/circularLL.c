#include <stdio.h>
#include <stdlib.h>

struct Node{

    int data;
    struct Node* next;
};

struct Node* head=NULL;
struct Node* temp=NULL;

void Insert(int elem){

    struct Node* newNode=malloc(sizeof(struct Node));

    if (head==NULL){
        head=newNode;
        head->data=elem;
        head->next=NULL;

        temp=head;
    }

    else{
        temp->next=newNode;

        newNode->data=elem;
        newNode->next=head;
        temp=newNode;
    }
}

void Delete(){

    struct Node* ptr;
    struct Node* t;

    ptr=head;

    if (head==NULL){
        printf("\nElement does not exist! ");
    }

    else{

        if (ptr==head && ptr->next==head){//that is only 1 element is there in the LL 
                                        //while using this delete function
            free(head);
            head=NULL;
        }

        else if (head->next!=NULL){//ie only 1 element in LL without using this function at all
            free(head);
            head=NULL;
        }

        else{

            while(ptr->next!=head){
                ptr=ptr->next;
            }

            t=ptr->next;//node to be deleted
            ptr->next=head;

            free(t);
            t=NULL;
        }
    }

}

void Display(){
    
    struct Node* ptr=head;

    if (head==NULL){
        printf("\nLL Empty\n");
    }

    else{

        while(ptr->next!=head){
            printf("%d ",ptr->data);
            ptr=ptr->next;
        }
        ptr=ptr->next;
        printf("%d ",ptr->data);

        ptr=ptr->next;
        printf("%d ",ptr->data);

    }

}

int main(){

    int choice;
    int elem;

    do{

        printf("\n1.Insert");
        printf("\n2.Delete");
        printf("\n3.Display");
        printf("\n4.Exit");

        printf("\n\nChoice: ");
        scanf("%d",&choice);

        switch(choice){

            case 1:
                printf("Enter the element: ");
                scanf("%d",&elem);
                Insert(elem);
                break;
            
            case 2:
                Delete();
                break;
            
            case 3:
                Display();
                break;
            
            case 4:
                printf("\n");
                break;
            
            default:
                printf("\nInvalid Choice!");

        }

    }while (choice!=4);

}