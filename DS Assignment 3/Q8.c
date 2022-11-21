#include <stdio.h>
#define MaxTerms 20

char Stack[MaxTerms];
int top=-1;

void Push(char Element){

	if(top==(MaxTerms)-1){
		printf("The Stack is full!");
		printf("\n");
	}
	
	else{
		Stack[++top]=Element;
		printf("Element %d is pushed",Element);
		printf("\n");
	}
}

int Pop(){
	if (top==-1){
		printf("The Stack is empty");
		printf("\n");
	}
	
	else{
		int x=Stack[top--];
		return x;
	}
}

char Peek(){

	if (top==-1){
		printf("The Stack is Empty");
		printf("\n");
	}
	
	else{
		return Stack[top];
	}
}


int PriorityOrder(char operator){

	int Priority;
	
	switch (operator){
			
		case '+':
		case '-':
			return 1;
			break;
		
		case '*':
		case '/':
			return 2;
			break;
		
		case '^':
			return 3;
			break;	
	}
	
}


int main(){
	
	char Infix[MaxTerms],PostFix[MaxTerms],c;
	
	printf("Enter the Infix Expression: ");
	scanf("%s",Infix);
	
	
	int x;
	int i=0,k=0;
	
	while(Infix[i]!='\0'){
		
		c=Infix[i];
		
		switch(c){
			
			case '+':
			case '-':
			case '*':
			case '/':
			case '^':
				
				if (PriorityOrder(c)>PriorityOrder(Stack[top])){
					Push(c);
				}
				
				else{
					x=Pop();
					PostFix[k]=x;
					Push(c);
					k++;
				}
				
				break;
			
			case '(':
				Push(c);
				break;
			
			case ')':
				
				while(Peek()!='('){
					
					PostFix[k]=Pop();
					k++;
				}
				break;
			
			default:
				PostFix[k]=c;
				k++;
				break;
		}
		
		i++;
	}
	
	PostFix[++k]='\0';
	
	i=0;
	
	while(PostFix[i]!='\0'){
		printf("%c",PostFix[i]);
		i++;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}	
