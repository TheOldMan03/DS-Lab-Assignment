#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* front=NULL;
struct Node* rear=NULL;

void IsEmpty(int elem){ //DRY---->Don't Repeat Yourself

    struct Node* newNode=malloc(sizeof(struct Node));

    front=newNode;
    rear=newNode;

    front->data=elem;
    front->next=NULL;

}

void EnqueueFront(int elem){

    struct Node* newNode=malloc(sizeof(struct Node));

    if (front==NULL){ //Queue Empty
        IsEmpty(elem);
    }

    else{

        rear->next=newNode; //Updating the 'next' part of the previous Node before updating rear

        rear=newNode; //rear is now the new Node (No Shit Sherlock)

        rear->data=elem;
        rear->next=NULL;

    }

}

void EnqueueBack(int elem){

    struct Node* newNode=malloc(sizeof(struct Node));

    if (front==NULL){ //Queue Empty
        IsEmpty(elem);
    }

    else{
        newNode->next=front;
        front=newNode;
        front->data=elem;
        
    }

}

void DeQueueBack(){

    struct Node* temp;
    struct Node* ptr;

    ptr=front;

    while(ptr->next!=rear){
        ptr=ptr->next;
    }

    rear=ptr;
    temp=ptr->next;

    rear->next=NULL;

    free(temp);
    temp=NULL;
  
}

void DeQueueFront(){
    
    struct Node* ptr;

    if (front==NULL){
        printf("Queue empty");
    }

    else{

        if (front==rear && rear!=NULL){

            free(front);
            front=NULL;
            rear=NULL;
        }

        else{

            ptr=front;
            front=front->next;

            ptr->next=NULL;
            free(ptr);
            ptr=NULL;
        }
    }   

}

void Display(){

    struct Node* ptr;
    ptr=front;

    if (front==NULL){
        printf("\nThe Queue is empty\n");
    }

    else{

        while(ptr!=NULL){
            printf("%d ",ptr->data);
            ptr=ptr->next;
        }
    }

}


int main(){

    int choice;
    int elem;

    printf("Double Ended Queue");

    do{

        printf("\n1.Enqueue");
        printf("\n2.Dequeue ");
        printf("\n3.Display");
        printf("\n4.Exit\n\n");

        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){

            case 1:

                int c1;

                printf("\n1.Insert at front");
                printf("\n2.Insert at back\n\n");

                printf("Enter the choice: ");
                scanf("%d",&c1);

                switch(c1){

                    case 1:

                        printf("\nEnter the element: ");
                        scanf("%d",&elem);

                        EnqueueFront(elem);
                        break;
                    
                    case 2:
                        printf("\nEnter the element: ");
                        scanf("%d",&elem);

                        EnqueueBack(elem);
                        break;

                    default:
                        printf("\nInvalid choice!\n");

                }

                break;
            
            case 2:
                int c2;

                printf("\n1.Delete from front");
                printf("\n2.Delete from back\n\n");

                printf("Enter the choice: ");
                scanf("%d",&c2);

                switch(c2){

                    case 1:
                        DeQueueFront();
                        break;

                    case 2:
                        DeQueueBack();
                        break;

                    default:
                        printf("\nInvalid Choice! ");

                }

                break;
            
            case 3:
                Display();
                break;
            
            case 4:
                printf("");
                break;

            default:
                printf("\nInvaild Choice!");

        }

    }while(choice!=4);

}