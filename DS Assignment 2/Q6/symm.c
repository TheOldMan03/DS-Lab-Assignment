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

    Sparse Trans[((a[0].row*a[0].col)+1)];

    Trans[0].row = a[0].col;
    Trans[0].col = a[0].row;
    Trans[0].val = a[0].val;

    int rowTerms[a[0].col];
    int startpos[a[0].col];

    int i,j;

    startpos[0] = 1;

    for (i = 0; i < a[0].col; i++) {
        rowTerms[i] = 0;
    }

    for (i = 1; i <= a[0].val; i++) {
        rowTerms[a[i].col]++;
    }

    for (i = 1; i < a[0].col; i++) {
        startpos[i] = startpos[i - 1] + rowTerms[i - 1];
    }

    for (i = 1; i <= a[0].val; i++) {
        j = startpos[a[i].col]++;
        Trans[j].row = a[i].col;
        Trans[j].col = a[i].row;
        Trans[j].val = a[i].val;
    }

    int symm_flag=1;

    for (i=0;i<a[0].val;i++){

        if (a[i].row!=Trans[i].row || a[i].col!=Trans[i].col || a[i].val!=Trans[i].val){
            symm_flag=0;
            break;
        }

    }

    if (symm_flag==0){
        printf("The given matrix is not symmetric!");
    }
    
    else{
        printf("The given matrix is symmetric!");
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