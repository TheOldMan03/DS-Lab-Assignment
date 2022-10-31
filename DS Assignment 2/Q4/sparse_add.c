#include <stdio.h>
#define MAX 50

typedef struct{

    int row;
    int col;
    int val;

}Sparse;

void Sparse_Converter(int rows,int cols,int k,Sparse s_m[]){

	s_m[0].row=rows;
	s_m[0].col=cols;
	s_m[0].val=k;
	
	int i;
	int x,y,z;
	int c=1;
	
	
	for(i=0;i<k;i++){
	
		
		printf("Enter the Row in which the Element lies in: ");
		scanf("%d",&x);
		
		printf("Enter the Coloumn in which the Element lies in: ");
		scanf("%d",&y);
		
		printf("Enter the Non Zero element: ");
		scanf("%d",&z);
		printf("\n");
		
		s_m[c].row=x;
		s_m[c].col=y;
		s_m[c].val=z;
		
		c++;	
	}
	
	printf("------------------------------");
	printf("\n");
	

    
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

        printf("\nThe resultant Sparse Matrix is: ");

        for(i=0;i<k;i++){

            printf("\n%d\t%d\t%d",Sum[i].row,Sum[i].col,Sum[i].val);
        }






    }

    else{
        printf("The given matrix cannot be added! ");
    }



}


int main(){

    Sparse a[MAX+1];
    Sparse b[MAX+1];
    
    int r1,c1,r2,c2,k1,k2;
    
    printf("Enter the numbers of Rows for A: ");
	scanf("%d",&r1);
	
	printf("Enter the Number of Coloumns for A: ");
	scanf("%d",&c1);
	
	printf("Enter the Number of Non Zero Elements present in the Matrix: ");
	scanf("%d",&k1);
	printf("\n");
	
	printf("Enter the numbers of Rows for B: ");
	scanf("%d",&r2);
	
	printf("Enter the Number of Coloumns for B: ");
	scanf("%d",&c2);
	
	printf("Enter the Number of Non Zero Elements present in the Matrix: ");
	scanf("%d",&k2);
	printf("\n");
	

    Sparse_Converter(r1,c1,k1,a);
    Sparse_Converter(r2,c2,k2,b);

    Sparse_Adder(a,b);


}





