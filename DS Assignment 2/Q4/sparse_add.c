#include <stdio.h>
#define MAX 50

typedef struct{

    int row;
    int col;
    int val;

}Sparse;

void Sparse_Converter(int rows,int cols,Sparse s_m[]){

	int r,c,k;

	printf("Enter the Number of Non Zero Elements present in the Matrix: ");
	scanf("%d",&k);
	
	printf("Enter the numbers of Rows: ");
	scanf("%d",&r);
	
	printf("Enter the Number of Coloumns: ");
	scanf("%d",&c);
	printf("\n");
	
	
	s_m[0].row=r;
	s_m[0].col=c;
	s_m[0].val=k;
	
	int i;
	int x,y,z;
	int c=1;
	
	
	for(i=0;i<k;i++){
		
		printf("Enter the Non Zero Element in the Array: ");
		scanf("%d",&x);
		
		printf("Enter the Row in which the Element lies in: ");
		scanf("%d",&y);
		
		printf("Enter the Coloumn in which the Element lies in: ");
		scanf("%d",&z);
		printf("\n");
		
		s_m[c].row=y;
		s_m[c].col=z;
		s_m[c].val=x;
		
		c++;	
	}
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






