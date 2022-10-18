#include <stdio.h>

void Mean_Median_Mode(int a[],int n){
	
	double sum=0.0;
	int count; //Sum is for mean, count is for mode, 
	int mode;
	double mean,median;
	//First Sorting the Array using Bubble Sorting
	
	int freq_count[n];
	
	int i,j,temp;
	
	for (i=0;i<n;i++){
		
		for (j=0;j<n-i;j++){
			
			if (a[j]>a[j+1]){
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	
	
	if (n%2==0)
		median=(a[n/2-1]+a[n/2])/2.0;
	
	else
		median=a[n/2-1];
	
	//Calculating Mean
	
	for (i=0;i<n;i++){
		sum+=a[i];
	}
	
	mean=sum/n;
	
	//Calculating Mode
	//l=[1,2,3,5,4,5,6,3,1,1]
	//l=[1,1,1,2,3,3,4,5,5,6]
	
	for (i=0;i<n;i++){
		freq_count[i]=0;
	}
	
	for (i=0;i<n;i++){
		count=1;
		
		for (j=i+1;j<n;j++){
			
			if (freq_count[j]!=-1){
			
				if (a[i]==a[j]){
					count++;
					freq_count[j]=-1;
				}
			}
		}
		
		freq_count[i]=count;
		
	}
	
	int l=freq_count[0],x=0;
	
	for (i=0;i<n;i++){
		
		if (freq_count[i]>l){
			l=freq_count[i];
			x=i; //The Position
		}
	}
	
	mode=a[x];
	
	printf("The Mean is %lf",mean);
	printf("\n");
	printf("The Median is %lf",median);
	printf("\n");
	printf("The mode is %d",mode);
	
	
}

void main(){
	
	int arr[10]={1,2,3,5,4,5,6,3,1,1};
	
	Mean_Median_Mode(arr,10);
}

