#include <stdio.h>
#include <math.h>

void Bin_to_Hex(int a[][4],int m){
	
	
	int Hex[m];
	int sum;
	
	int i,j,k;
	
	for (i=0;i<m;i++){
		sum=0;
		k=3;
		
		for (j=0;j<4;j++){
			
			sum+=a[i][j]*(pow(2,k));
			k--;
			
		}
		
		Hex[i]=sum;
	}
	
	//A-10,B-11,C-12,D-13,E-14,F-15
	
	for (i=0;i<m;i++){
		
		if (Hex[i]==10){
			printf("%c",'A');
			printf("\n");
		}
		
		else if (Hex[i]==11){
			printf("%c",'B');
			printf("\n");
		}
		
		else if (Hex[i]==12){
			printf("%c",'C');
			printf("\n");
		}
		
		else if (Hex[i]==13){
			printf("%c",'D');
			printf("\n");
		}
		
		else if (Hex[i]==14){
			printf("%c",'E');
			printf("\n");
		}
		
		else if (Hex[i]==15){
			printf("%c",'F');
			printf("\n");
		}
		
		else{
			printf("%d",Hex[i]);
			printf("\n");
		}
	}
	
	
	
	
}


int main(){
	
	int a[3][4]={{1,0,1,1},{1,1,0,1},{1,0,0,1}};
	
	Bin_to_Hex(a,3);
	
}