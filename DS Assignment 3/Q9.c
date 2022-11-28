#include <stdio.h>
#define MaxTerms 20

int Stack[MaxTerms];
int top=-1;

void Push(int Element){

	if(top==(MaxTerms)-1){
		printf("The Stack is full!");
		printf("\n");
	}
	
	else{
		Stack[++top]=Element;
	}
}

int Pop(){
	if (top==-1){
		printf("The Stack is empty");
		printf("\n");
	}
	
	else{
		char x=Stack[top--];
		return x;
	}
}

int Peek(){

	if (top==-1){
		printf("The Stack is Empty");
		printf("\n");
	}
	
	else{
		return Stack[top];
	}
}


int main(){
	char postfix[MaxTerms];
	printf("Enter the Postfix Expression: ",postfix);
	scanf("%s",postfix);
	
	int i=0;
	int e;
	char c;
	
	while (postfix[i]!='\0'){
		
		c=postfix[i];
		int x,y;
		
		switch(c){
			
			case '+':
				y=Pop();
				x=Pop();
				
				e=y+x;
				Push(e);
				break;
					
			case '-':
				y=Pop();
				x=Pop();
				
				e=y-x;
				Push(e);
				break;
				
			
			case '*':
				y=Pop();
				x=Pop();
				
				e=y*x;
				Push(e);
				break;
				
			case '/':
				y=Pop();
				x=Pop();
				
				e=y/x;
				Push(e);
				break;
				
			case '^':
				y=Pop();
				x=Pop();
				
				e=y^x;
				Push(e);
				break;
				
			case ' ':
				continue;
				//ignoring spaces
			
			default:
				e=c-48;
				Push(e);
				break;

		}
		
		i++;	
	}
	
	printf("\n%d",Stack[top]);
	
}





