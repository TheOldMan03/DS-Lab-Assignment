#include <stdio.h>

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
	
	printf("\n");
	
	for(i=0;i<k;i++){
		
		printf("Enter the Row in which the Element lies in: ");
		scanf("%d",&x);
		
		printf("Enter the Coloumn in which the Element lies in: ");
		scanf("%d",&y);
		
		printf("Enter the Non Zero Element in the Array: ");
		scanf("%d",&z);
		printf("\n");
		
		s_m[c].row=x;
		s_m[c].col=y;
		s_m[c].val=z;
		
		c++;	
	}
	
	printf("\n");
    
}


void Transpose(Sparse a[]){ //Simple Transpose Algorithm

    Sparse b[a[0].val+1];

    b[0].row=a[0].col;
    b[0].col=a[0].row;
    b[0].val=a[0].val;


    int i,j,k=1;

    for(i=0;i<a[0].col;i++){

        for(j=1;j<=a[0].val;j++){

			if (a[j].col==i){
				
				b[k].row=a[j].col;
				b[k].col=a[j].row;
				b[k].val=a[j].val;
				k++;

			}
    	}
	}

    for(i=0;i<=b[0].val;i++){

        printf("\n%d\t%d\t%d",b[i].row,b[i].col,b[i].val);
    }
    
}

int main(){

	int r,c,k;
	
	printf("Enter the numbers of Rows: ");
	scanf("%d",&r);
	
	printf("Enter the Number of Coloumns: ");
	scanf("%d",&c);
	
	printf("Enter the Number of Non Zero Elements present in the Matrix: ");
	scanf("%d",&k);
	
    Sparse A[(r*c)+1];

    Sparse_Converter(r,c,k,A);
    Transpose(A);

    return 0;

}
