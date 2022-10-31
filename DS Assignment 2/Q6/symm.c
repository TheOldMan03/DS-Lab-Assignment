#include <stdio.h>

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
