#include <stdio.h>
#include <stdlib.h>

struct Node{

    int data;
    struct Node* next;
};

struct Node* head=NULL;
struct Node* tail=NULL; //The last added Node in the list and Not actually the tail of the list

void Insert(int elem){

    struct Node* newNode=malloc(sizeof(struct Node));

    if (head==NULL){
        head=newNode;
        head->data=elem;
        head->next=NULL;

        tail=head;
    }

    else{
        tail->next=newNode;

        newNode->data=elem;
        newNode->next=head;

        tail=newNode;
    }
}

void Delete(){

    struct Node* ptr;

    ptr=head;

    if (head==NULL){
        printf("\nList is empty ");
    }

    else{//Deleting Head would be better than deleting tail for efficiency purpose


        if (head->next==NULL){//Only 1 element in the list
            free(head);
            head=NULL;
        }

        else{

            head=ptr->next; //Updating ptr to the next address without losing the previous head address

            if (tail==head){ //ie there were 2 elems,and now only 1 remains
                head->next=NULL; //it is no longer circular since only 1 element is there
            }

            else{
                tail->next=head;//Updating the last added node's next addr to head
            }

            free(ptr);
            ptr=NULL;
        }
        printf("\nDeletion Successful");

    }

}

void Display(){
    
    struct Node* ptr=head;

    if (head==NULL){
        printf("\nLL Empty\n");
    }

    else{

        printf("%d ",head->data);
        ptr=ptr->next;

        while(ptr!=head && ptr!=NULL){
            printf("%d ",ptr->data);
            ptr=ptr->next;
        }
    
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
                break;

        }

    }while (choice!=4);

}