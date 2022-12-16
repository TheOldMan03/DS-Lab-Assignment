#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* head=NULL;
struct Node* tail=NULL;


void InsertFront(int elem){ //Adding from the front

    struct Node* newNode=malloc(sizeof(struct Node));

    if (head==NULL){
        head=newNode;

        head->data=elem;
        head->next=NULL;

        tail=newNode;
        
      

    }

    else{
        tail->next=newNode; //Pointing to the previous node and updating the address bit

        tail=newNode;
        tail->data=elem;
        tail->next=NULL;

    }
}

void Duplicate(){

    struct Node* ptr1=head;
    struct Node* ptr2=head->next;
    
    int x;

    x=ptr1->data;

    while(ptr1!=NULL){

        while(ptr2!=NULL && x!=-1){
            
            if (x==(ptr2->data)){
                ptr2->data=-1;
            }

            ptr2=ptr2->next;
        
        }

        ptr1=ptr1->next;

        if (ptr1==NULL){
            break;
        }

        else{
            x=ptr1->data;
            ptr2=ptr1->next;

        }
    }

    /*

    ptr1=head;
    ptr2=head->next;

    struct Node* temp;
    
    while(ptr2!=NULL){

        if (ptr2->data==-1){
       
            temp=ptr2;
            ptr1->next=ptr2->next;

            ptr2=ptr2->next;
            ptr1=ptr1->next;

            free(temp);
            temp=NULL;

        }

        else{

            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }

    }
    */

    printf("Duplicate Elements removed!\n");

}

void Display(){
    struct Node* ptr;
    ptr=head;

    if (head==NULL){
        printf("List empty!\n");
    }

    else{
        printf("\n");

        while(ptr!=NULL){

            if (ptr->data!=-1){
                printf("%d ",ptr->data);
            }
            ptr=ptr->next;
        }

    }
    
}

int main(){

    int n;
    printf("Enter the number of elements you want to add: ");
    scanf("%d",&n);

    int i;
    int elem;

    printf("Enter all the elements \n");

    for(i=0;i<n;i++){
        scanf("%d",&elem);
        InsertFront(elem);
    }

    printf("\nBefore Deleting the Duplicate Elements\n");
    Display();

    Duplicate();

    printf("After Deleting the Duplicate Elements\n");
    Display();

    return 0;
}
