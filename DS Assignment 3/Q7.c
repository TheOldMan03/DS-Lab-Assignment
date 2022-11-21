#include <stdio.h>
#define MaxTerms 10

char Stack[MaxTerms];
int top=-1;

void Push(char Element){

	if(top>=(MaxTerms)-1){
		printf("The Stack is full!");
		printf("\n");
	}
	
	else{
		Stack[++top]=Element;
	}
}

void Pop(){
	if (top==-1){
		printf("The Stack is empty");
		printf("\n");
	}
	
	else{
		--top;
	}
}


int main(){
	
	
	char S[10],c;
	
	printf("Enter the string : ");
	scanf("%s",S);
	
	int i;
	
	for(i=0;S[i]!='\0';i++){
		c=S[i];
		
		switch(c){
			
			case '(':
			case '{':
			case '[':
				
				Push(c);
				break;
			
			case ')':
				
				if (Stack[top]=='('){
					Pop();
				}
				
				else{
					Push(c);
				}
			
				break;
			
			case '}':
				
				if (Stack[top]=='{'){
					Pop();
				}
				
				else{
					Push(c);
				}
			
				break;
			
			case ']':
			
				if (Stack[top]=='['){
					Pop();
				}
				
				else{
					Push(c);
				}
			
				break;
			
			default:
				continue;			
		}		
	}
	
	if (top==-1){
		printf("The Expression is balanced");
	}
	
	else{
		printf("The expression is not balanced");
	}	
}
