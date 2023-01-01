#include <stdio.h>
#include <stdlib.h>

//creating the skeleton of the LL
struct term{
    int coeff;
    int expon;
    struct term* next;
    struct term* prev;
};

//tail is used to reduce the time complexity from O(n) to O(1) while inserting in the end

//for Polynomial A
struct term* headA=NULL;
struct term* tailA=NULL;

//for Polynomial B
struct term* headB=NULL;
struct term* tailB=NULL;

//for the Resultant Polynomial 
struct term* headC=NULL;
struct term* tailC=NULL;


void InsertTerms(struct term** head,struct term** tail,int coefficient,int exponent){

    struct term* newNode=malloc(sizeof(struct term));

    if (*head==NULL){

        *head=newNode;

        newNode->coeff=coefficient;
        newNode->expon=exponent;
        newNode->next=NULL;
        newNode->prev=NULL;

        *tail=newNode;
    }

    else{
        
        (*tail)->next=newNode;
        newNode->prev=*tail;

        newNode->coeff=coefficient;
        newNode->expon=exponent;
        newNode->next=NULL; 

        *tail=newNode;

    }
}

void Display(struct term** head){

    if (head==NULL){
        printf("\nThere are no terms in the Polynomial!");
    }

    else{
        struct term* ptr=(*head);

        while(ptr->next!=NULL){
            printf("%dx^%d +",ptr->coeff,ptr->expon);
            ptr=ptr->next;
        }

        printf("%dx^%d ",ptr->coeff,ptr->expon);

    }
}

void PAdd_Or_PSub(struct term** HeadA,struct term** HeadB,int c){ //c is used to determine whether addition or subtraction is need
//this saves the code to rewrite this function just for subraction

    struct term* ptrA=*HeadA;
    struct term* ptrB=*HeadB;

    while(ptrA!=NULL && ptrB!=NULL){

        if ((ptrA->expon)>(ptrB->expon)){
            InsertTerms(&headC,&tailC,ptrA->coeff,ptrA->expon);
            ptrA=ptrA->next;
        }

        else if ((ptrA->expon)<(ptrB->expon)){

            if (c==0){
                InsertTerms(&headC,&tailC,ptrB->coeff,ptrB->expon);
            }

            else{
                InsertTerms(&headC,&tailC,-(ptrB->coeff),ptrB->expon);
            }
            ptrB=ptrB->next;
        }

        else{

            if (c==0){//for addition
                int add=ptrA->coeff+ptrB->coeff;
                InsertTerms(&headC,&tailC,add,ptrB->expon);
            }

            else{//for subraction
                int sub=ptrA->coeff-ptrB->coeff;
                InsertTerms(&headC,&tailC,sub,ptrB->expon);
            }
            ptrA=ptrA->next;
            ptrB=ptrB->next;

        }
    }

    while(ptrA!=NULL){
        InsertTerms(&headC,&tailC,ptrA->coeff,ptrA->expon);
        ptrA=ptrA->next;
    }

    while(ptrB!=NULL){
        if (c==0){
            InsertTerms(&headC,&tailC,ptrB->coeff,ptrB->expon);
        }

        else{
            InsertTerms(&headC,&tailC,-(ptrB->coeff),ptrB->expon);
        }            
        ptrB=ptrB->next;
    }

    printf("Done! ");

    //here the resultant LL is getting updated by the InsertFunction and therefore 
    //there is no need to check on that LL
}

void DeleteNode(struct term** currptr){//it will never be the 1st node to be deleted
    
    ((*currptr)->prev)->next =(*currptr)->next;
    ((*currptr)->next)->prev=(*currptr)->prev;

    (*currptr)->next=NULL;
    (*currptr)->prev=NULL;

    free(*currptr);
    *currptr=NULL;
}

void PMulti(struct term** HeadA,struct term** HeadB){//Need to add Like terms together
    struct term* ptrA=*HeadA;
    struct term* ptrB=*HeadB;

    int p_coeff,p_expon;

    while(ptrA!=NULL){

        while(ptrB!=NULL){
            p_coeff=(ptrA->coeff)*(ptrB->coeff);
            p_expon=(ptrA->expon)+(ptrB->expon);
            InsertTerms(&headC,&tailC,p_coeff,p_expon);

            ptrB=ptrB->next;
        }

        ptrB=*HeadB;
        ptrA=ptrA->next;
    }

    struct term* ptrC=headC->next;
    struct term* ptrNext;
    struct term* temp;


    while(ptrC!=NULL){

        int x=ptrC->expon;
        ptrNext=ptrC->next;

        while(ptrNext!=NULL){
            
            if(x==ptrNext->expon){
                ptrC->coeff+=ptrNext->coeff;
                temp=ptrNext->prev;
                DeleteNode(&ptrNext);
                ptrNext=temp;
                
            }

            ptrNext=ptrNext->next;
        }
        ptrC=ptrC->next;
    }
}

void TakeTerms(){
    
    int t1,t2,i;
    int coeff,expon;

    printf("\nEnter the number of terms for PolyA: ");
    scanf("%d",&t1);

    printf("\nEnter the number of terms for PolyB: ");
    scanf("%d",&t2);

    //here t1 and t2 is meant for taking all the terms all at once instead of taking it one by one

    for(i=0;i<t1;i++){
        printf("\nEnter the coeff of PolyA: ");
        scanf("%d",&coeff);

        printf("Entet the expon of PolyA: ");
        scanf("%d",&expon);

        InsertTerms(&headA,&tailA,coeff,expon);
        
    }

    for(i=0;i<t2;i++){
        printf("\nEnter the coeff of PolyB: ");
        scanf("%d",&coeff);

        printf("Entet the expon of PolyB: ");
        scanf("%d",&expon);

        InsertTerms(&headB,&tailB,coeff,expon);
        
    }
}

int main(){
    TakeTerms();
    PMulti(&headA,&headB);
    Display(&headC);
}