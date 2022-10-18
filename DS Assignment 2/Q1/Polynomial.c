#include <stdio.h>
#include <stdlib.h>

struct Polynomial{
    int coeff;
    int expon;
    struct Polynomial *next_add;
};

int main(){
    struct Polynomial a,b;

    int* head1=NULL,head2=NULL;
    int* temp1=NULL,temp2=NULL;
    int* t=NULL;

    int terms1=0,terms2=0;

    printf("Enter the number of terms in Polynomial A: ");
    scanf("%d",&terms1);
    printf("\n");

    printf("Enter the number of terms in Polynomial B: ");
    scanf("%d",&terms2);
    printf("\n");

    int i;

    printf("For Polynomial A");
    
    for(i=0;i<terms1;i++){

        temp1=malloc(sizeof(a));

        printf("Enter the Coefficent of term %d: ",i+1);
        scanf("%d",&(temp1->coeff));
        printf("\n");

        printf("Enter the Value of term %d: ",i+1);
        scanf("%d",&(temp1->coeff));
        printf("\n");

        if (head1==NULL){
            temp1=head1;
        }

        else{
            
            t=head1;

            while(t->next_add!=NULL){
                t=t->next_add;
            }
            t=t->next_add;

        }
    }

    printf("For Polynomial B");

    for(i=0;i<terms1;i++){

        temp1=malloc(sizeof(b));

        printf("Enter the Coefficent of term %d: ",i+1);
        scanf("%d",&(temp1->coeff));
        printf("\n");

        printf("Enter the Value of term %d: ",i+1);
        scanf("%d",&(temp1->coeff));
        printf("\n");

        if (head1==NULL){
            temp1=head1;
        }

        else{
            
            t=head1;

            while(t->next_add!=NULL){
                t=t->next_add;
            }
            t=t->next_add;

        }




    return 0;
}