#include <stdio.h>
#include <math.h>

typedef struct{
    
    int coeff;
    int expon;
}Polynomial;


void EvalSum(Polynomial p[],int terms,int x){

    int i,sum=0;

    for (i=0;i<terms;i++){

        sum+=pow(x,p[i].expon)*(p[i].coeff);

    }

    printf("The evaluated Polynomial is %d ",sum);

}

int main(){

    int terms;

    printf("Enter the number of terms for the Polynomial: ");
    scanf("%d",&terms);
    printf("\n");

    Polynomial p[terms];

    int i;

    for (i=0;i<terms;i++){

        printf("Enter the Coefficient of the term %d: ",i+1);
        scanf("%d",&(p[i].coeff));

        printf("Enter the Exponent of the term %d: ",i+1);
        scanf("%d",&(p[i].expon));
        printf("\n");

    }

    int x;

    printf("Enter the Value of x: ");
    scanf("%d",&x);
    printf("\n");

    EvalSum(p,terms,x);
}