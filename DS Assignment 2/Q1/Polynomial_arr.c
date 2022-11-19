#include <stdio.h>

typedef struct 
{
    int coeff;
    int expon;
    
}Polynomial;

void PAdd(Polynomial p1[],Polynomial p2[],int terms1,int terms2){

    int terms3=terms1+terms2;

    Polynomial sum[terms3];

    int startA=0,startB=0,startC=0;

    while (startA<terms1 && startB<terms2){

        if (p1[startA].expon>p2[startB].expon){

            sum[startC].expon=p1[startA].expon;
            sum[startC].coeff=p1[startA].coeff;

            startA++;
            startC++;

        }

        else if (p1[startA].expon<p2[startB].expon){

            sum[startC].expon=p2[startB].expon;
            sum[startC].coeff=p2[startB].coeff;

            startB++;
            startC++;

        }


        else{

            sum[startC].expon=p1[startA].expon;
            sum[startC].coeff=p1[startA].coeff+p2[startB].coeff;

            startA++;
            startB++;
            startC++;
        }

    }

    while (startA<terms1){
        sum[startC].expon=p1[startA].expon;
        sum[startC].coeff=p1[startA].coeff;
        startA++;
        startC++;

    }


    while (startB<terms2){
        sum[startC].expon=p2[startB].expon;
        sum[startC].coeff=p2[startB].coeff;
        startB++;
        startC++;

    }

    int i;

    printf("%dx^%d+",sum[0].coeff,sum[0].expon);
    for (i=1;i<=startC-2;++i){
        printf("%dx^%d+",sum[i].coeff,sum[i].expon);
    }
    printf("%dx^%d",sum[startC-1].coeff,sum[startC-1].expon);

}


int main(){

    int terms1,terms2;

    printf("\nEnter the number of terms of Polynomial A: ");
    scanf("%d",&terms1);

    printf("Enter the number of terms of Polynomial B: ");
    scanf("%d",&terms2);
    printf("\n");

    Polynomial p1[terms1],p2[terms2];

    int i;

    for (i=0;i<terms1;i++){

        printf("Enter the Coefficient of the term %d for PolyA: ",i+1);
        scanf("%d",&(p1[i].coeff));

        printf("Enter the Exponent of the term %d for PolyA: ",i+1);
        scanf("%d",&(p1[i].expon));

        printf("\n");


    }

    for (i=0;i<terms2;i++){

        printf("Enter the Coefficient of the term %d for PolyB: ",i+1);
        scanf("%d",&(p2[i].coeff));
        

        printf("Enter the Exponent of the term %d for PolyB: ",i+1);
        scanf("%d",&(p2[i].expon));
        printf("\n");

    }

    PAdd(p1,p2,terms1,terms2);

}
