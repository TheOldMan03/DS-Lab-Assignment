#include <stdio.h>

typedef struct{

    int row;
    int col;
    int val;

}Sparse;

void Sparse_Converter(int r,int c,Sparse a[]){

    int i,j,k=1;
    int elem;

    for (i=0;i<r;i++){

        for(j=0;j<c;j++){

            printf("Enter the Data: ");
            scanf("%d",&elem);

            if (elem!=0){

                a[k].row=i;
                a[k].col=j;
                a[k].val=elem;
                k++;

            }

        }
        printf("\n");
    }

    a[0].row=r;
    a[0].col=c;
    a[0].val=k-1;

}

void Transpose(Sparse a[]){

    Sparse b[a[0].val+1];

    b[0].row=a[0].col;
    b[0].col=a[0].row;
    b[0].val=a[0].val;


    int i,j,k=1;

    for(i=0;i<a[0].col;i++){

        for(j=1;j<a[0].val;j++)

        if (a[j].col==i){
            
            b[k].row=a[j].col;
            b[k].col=a[j].row;
            b[k].val=a[j].val;
            k++;

        }


    }
}

int main(){

    int r,c;

    printf("\nEnter the number of rows :");
    scanf("%d",&r);

    printf("Enter the number of coloumns :");
    scanf("%d",&c);
    printf("\n");

    Sparse A[(r*c)+1];

    Sparse_Converter(r,c,A);
    Transpose(A);

    int i;

    return 0;



}