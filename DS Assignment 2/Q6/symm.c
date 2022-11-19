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
}

void Transpose(Sparse a[]){

    Sparse Trans[a[0].val+1];

    Trans[0].row=a[0].col;
    Trans[0].col=a[0].row;
    Trans[0].val=a[0].val;


    int i,j,k=1;

    for(i=0;i<a[0].col;i++){

        for(j=1;j<=a[0].val;j++)

        if (a[j].col==i){
            
            Trans[k].row=a[j].col;
            Trans[k].col=a[j].row;
            Trans[k].val=a[j].val;
            k++;

        }
    }


    printf("The Original Array");
    for(i=0;i<=a[0].val;i++){

        printf("\n%d\t%d\t%d",a[i].row,a[i].col,a[i].val);
    }
    printf("\n");

    printf("\n");
    printf("The Transpose Array");
    for(i=0;i<=Trans[0].val;i++){

        printf("\n%d\t%d\t%d",Trans[i].row,Trans[i].col,Trans[i].val);
    }


    int symm_flag=1;

    for (i=0;i<=a[0].val;i++){

        if (a[i].row!=Trans[i].row || a[i].col!=Trans[i].col || a[i].val!=Trans[i].val){
            symm_flag=0;
            break;
        }

    }

    if (symm_flag==0){
        printf("\nThe given matrix is not symmetric!");
    }
    
    else{
        printf("\nThe given matrix is symmetric!");
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
	printf("\n");
	
	

    Sparse A[(r*c)+1];

    Sparse_Converter(r,c,k,A);
    Transpose(A);

    int i;

    return 0;
}