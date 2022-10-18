#include <stdio.h>

int rotate(int a[],int n,char d,int cr){
	
	int temp,i,j;
	
	if (d=='l'|| d=='L'){ 
	
		/* 1st [1,2,3,4,5]
		2nd [2,3,4,5,1]
		3rd [3,4,5,1,2].....*/
	
		
		
		for (i=0;i<cr;i++){
			temp=a[0];
			for (j=0;j<n-1;j++){
				
				a[j]=a[j+1];				
			}			
			
			a[n-1]=temp;	
		
		}
		
		//Printing the elements
		for (i=0;i<n;i++){
			printf("%d",a[i]);
			printf("\n");
		
		
		}
	}
	
	else if (d=='r' || d=='R'){
		
		for (i=0;i<cr;i++){
			
			temp=a[n-1];
			
			for (j=n-1;j>0;j--){
				
				a[j]=a[j-1];
			}
		
			a[0]=temp;
		}
		
		for (i=0;i<n;i++){
			printf("%d",a[i]);
			printf("\n");
		}
		
	}	
	
		
}

void main(){
	
	int arr[6]={2,3,4,5,6,7};
	
	rotate(arr,6,'l',2);
}
		