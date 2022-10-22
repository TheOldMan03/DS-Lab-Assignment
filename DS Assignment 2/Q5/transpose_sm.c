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

    Sparse b[(a[0].row*a[0].col)+1];

    b[0].row=a[0].col;
    b[0].col=a[0].row;
    b[0].val=a[0].val;

    int n=a[0].val,cols=a[0].col,rows=a[0].row;

    int rowTerms[cols],startPOS[cols+1];
    int i,j;


    for(i=0;i<cols;i++){
        rowTerms[i]=0;
    }

    for(i=1;i<=n;i++){
        rowTerms[a[0].col]++;
    }

    startPOS[0]=1;
    
    for (i=1;i<cols;i++){
        startPOS[i]=startPOS[i-1]+rowTerms[i-1];
    }

    for(i=1;i<=n;i++){

        j=startPOS[a[i].col]++;
        b[j].row=a[i].col;
        b[j].col=a[i].row;
        b[j].val=a[i].val;

    }

    for (i=0;i<=b[0].val;i++){
        printf("%-2d\t%-2d\t%-2d",b[i].row,b[i].col,b[i].val);
        printf("\n");
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

    for (i=0;i<A[0].val;i++){
        printf("%-2d\t%-2d\t%-2d",A[i].row,A[i].col,A[i].val);
        printf("\n");
    }


    return 0;



}