#include <stdio.h>
#include <string.h>

void Freq_Count(){
	
	char s[100];
	int i=0,j,count=0;
	int x;
	
	int l;
	l=strlen(s);
	
	printf("Enter the string: ");
	scanf("%s",s);
	
	int frequency[256]={0};
	
	while (s[i]!='\0'){
		x=s[i]
		frequency[x]+=1;
		i++;	
	}
	
	printf("%s",s);
	
	
	
	for (i=0;i<l;i++){
		
		printf("%c - %d",s[i],frequency[s[i]]);
		printf("\n");
	}
	
	

	
}




int  main(){
	
	
	char s[100]="This is a test string";
	Freq_Count();
}
	