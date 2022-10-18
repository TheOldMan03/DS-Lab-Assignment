#include <stdio.h>

void Intersection(int a1[],int n1,int a2[],int n2){
	
	int i,j,k=0;
	
	int common[100];
	
	for (i=0;i<n1;i++){
		for (j=0;j<n2;j++){
			
			if (a1[i]==a2[j]){
				common[k]=a1[i];
				k++;
			}
		}
	}
	
	for (i=0;i<k;i++){
		printf("%d",common[i]);
		printf("\n");
	}
	
}

int main(){
	
	int n1,n2,i;
	
	printf("Enter the number of elements you want in array 1: ");
	scanf("%d",&n1);
	printf("\n");
	
	printf("Enter the number of elements you want in array 2: ");
	scanf("%d",&n2);
	printf("\n");
	
	int a1[n1],a2[n2];
	
	for (i=0;i<n1;i++){
		printf("Enter the element you want in array 1: ");
		scanf("%d",&a1[i]);
	}
	
	printf("\n");
	
	for (i=0;i<n2;i++){
		printf("Enter the element you want in array 2: ");
		scanf("%d",&a2[i]);
	}
	
	printf("\n");
	
}