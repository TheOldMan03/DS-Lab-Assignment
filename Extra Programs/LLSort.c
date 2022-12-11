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

void Insert(int elem){ //Adding from the front

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

void Sort(){ //Using Bubble Sort Algo

    int i,j,temp;
    struct Node* current;

    for(i=0;i<count;i++){
        current=head;

        for(j=0;j<count-1-i;j++){

            if ((current->data)>(current->next)->data){

                temp=current->data;
                current->data=(current->next)->data;
                (current->next)->data=temp;
            }

            current=current->next;

        }
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
            printf("%d",ptr->data);
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
        printf("\n2.Sort");
        printf("\n3.Display");
        printf("\n4.Exit\n");

        printf("Enter Choice: ");
        scanf("%d",&choice);

        switch(choice){

            case 1:
                printf("\nEnter value: ");
                scanf("%d",&elem);
                Insert(elem);
                break;
            
            case 2:
                Sort();
                break;
            
            case 3:
                Display();
                break;
            
            case 4:
                printf("\n");
                break;
            
            default:
                printf("Invalid Choice!");

        }
    } while(choice!=4);

    return 0;
}