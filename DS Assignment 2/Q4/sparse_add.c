#include <stdio.h>
#define MAX 50

typedef struct{

    int row;
    int col;
    int val;

}Sparse;

void Sparse_Converter(int rows,int cols,Sparse s_m[]){

    int i,j,k=1;
    int elem;

    for(i=0;i<rows;i++){
        for(j=0;j<cols;j++){

            printf("Enter the Data for the Matrix: ");
            scanf("%d",&elem);

            if (elem!=0){
                s_m[k].row=i;
                s_m[k].col=j;
                s_m[k].val=elem;
                k++;
            }

        }
        printf("\n");
    }
    printf("\n");
    printf("\n");

    s_m[0].row=rows;
    s_m[0].col=cols;
    s_m[0].val=k-1;

}

void Sparse_Adder(Sparse x[],Sparse y[]){

    if (x[0].row==y[0].row && x[0].col==y[0].col){

        int i=1,j=1,k=1;
        int terms;

        terms=x[0].val+y[0].val;

        Sparse Sum[terms];

        while (i<=x[0].val && j<=y[0].val){

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

        Sum[0].row=x[0].row;
        Sum[0].col=x[0].col;
        Sum[0].val=k-1;

        printf("The resultant Sparse Matrix is: ");

        for(i=0;i<k;i++){

            printf("\n%d\t%d\t%d",Sum[i].row,Sum[i].col,Sum[i].val);
        }






    }

    else{
        printf("The given matrix cannot be added! ");
    }



}


int main(){

    int r1,c1,r2,c2;

    printf("Enter the Number of rows A : ");
    scanf("%d",&r1);

    printf("Enter the Number of coloumns A: ");
    scanf("%d",&c1);
    printf("\n");

    printf("Enter the Number of rows B: ");
    scanf("%d",&r2);

    printf("Enter the Number of coloumns B: ");
    scanf("%d",&c2);
    printf("\n");


    Sparse a[MAX+1];
    Sparse b[MAX+1];

    Sparse_Converter(r1,c1,a);
    Sparse_Converter(r2,c2,b);

    Sparse_Adder(a,b);


}






