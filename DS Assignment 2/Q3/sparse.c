#include <stdio.h>
#define MAX 50
//That is the maximum number of non zero elements is 50

typedef struct{
    int row;
    int col;
    int val;

}sparse;

void Sparse(int rows,int cols,int A[][cols]){

    sparse s_m[MAX+1];

    int i,j,posnum=0,k=0;

    for (i=0;i<rows;i++){
        for(j=0;j<cols;j++){

            if (A[i][j]!=0){

                s_m[k].row=i;
                s_m[k].col=j;
                s_m[k].val=A[i][j];
                posnum++;
                k++; //The number of rows in sparse Matrix

            }
        }
    }

    s_m[0].row=rows;
    s_m[0].col=cols;
    s_m[0].val=posnum;

    printf("Then the given sparse Matrix is: ");

    for (i=0;i<posnum;i++){
        
        printf("\n%-2d\t%-2d\t%-2d",s_m[i].row,s_m[i].col,s_m[i].val);

    }
    printf("\n");

    float sparsity;

    sparsity=(float)((rows*cols)-(posnum))/(rows*cols);

    printf("The sparsity of the matrix is %f",sparsity);

}


int main(){

    int rows,cols;

    printf("\nEnter the number of rows :");
    scanf("%d",&rows);

    printf("Enter the number of coloumns :");
    scanf("%d",&cols);
    printf("\n");

    int i,j;

    int A[rows][cols];

    for (i=0;i<rows;i++){

        for (j=0;j<cols;j++){
            printf("Enter the Element: ");
            scanf("%d",&A[i][j]);
        }
        
        printf("\n");
    }

    Sparse(rows,cols,A);

}

