#include <stdio.h>

typedef struct{

    int row;
    int col;
    int val;

}Sparse;

void Sparse_Converter(Sparse a[]){

    int r,c;

    printf("Enter the Number of rows: ");
    scanf("%d",&r);

    printf("Enter the Number of coloumns: ");
    scanf("%d",&c);
    printf("\n");

    int i,j,k=1;
    int elem;
    int non_zero_nos;

    for(i=0;i<r;i++){
        for(j=0;j<c;j++){

            printf("Enter the Data for the Matrix: ");
            scanf("%d",&elem);

            if (elem!=0){
                a[k].row=i;
                a[k].col=j;
                a[k].val=elem;

                k++;
            }

        }
    }

    a[0].row=r;
    a[0].col=c;
    a[0].val=k-1;

}

void Sparse_Adder(Sparse x[],Sparse y[],Sparse Sum[]){

    if (x[0].row==y[0].row && x[0].col==y[0].col){

        int i=1,j=1,k=1;

        while (i<x[0].val && j<y[0].val){

            if (x[i].row<y[j].row || (x[i].row==y[j].row && x[i].col<y[j].col)){
                Sum[k].row=x[i].row;
                Sum[k].col=x[i].col;
                Sum[k].val=x[i].val;

                i++;
                k++;

            }

            else if (x[i].row>y[j].row || (x[i].row==y[j].row && x[i].col>y[j].col)){

                Sum[k].row=y[j].row;
                Sum[k].col=y[j].col;
                Sum[k].val=y[j].val;

                j++;
                k++;

            }

            else if (x[i].row==y[j].row && x[i].col==y[j].col){
                Sum[k].row=y[j].row;
                Sum[k].col=y[j].col;
                Sum[k].val=x[i].val+y[j].val;

                i++;
                j++;
                k++;

            }

        }

        while (i<x[0].val){

            Sum[k].row=x[i].row;
            Sum[k].col=x[i].col;
            Sum[k].val=x[i].val;

            i++;
            k++;

        }

        while (j<y[j].val){

            Sum[k].row=y[j].row;
            Sum[k].col=y[j].col;
            Sum[k].val=y[j].val;

            j++;
            k++;

        }

    }

    else{
        printf("The given matrix cannot be added! ");
    }



}









