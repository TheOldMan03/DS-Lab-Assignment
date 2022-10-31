#include <stdio.h>
#define MAX_STACK_SIZE 10

int Stack[MAX_STACK_SIZE];
int top=-1;

void Push(int Element){

	if(top>=(MAX_STACK_SIZE)-1){
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
		int x=Stack[--top];
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

void Display(){

	if (top==-1){
		printf("Stack Empty");
		printf("\n");
	}
	
	else{
		
		for(int i=top;i>=0;i--){
		
			printf("%d",Stack[i]);
			printf("\n");
		
		}	
	}

}


int main(){
	
	printf("\nStack Operations\n");
	int choice,elem;
	
	int y;
	
	do{
		
		printf("\n1.Push");
		printf("\n2.Pop");
		printf("\n3.Peek");
		printf("\n4.Display");
		printf("\n5.Exit");
		
		
		printf("\nChoose your option: ");
		scanf("%d",&choice);
		
		
		if (choice==1){
			
			printf("Enter the Element: ");
			scanf("%d",&elem);
			Push(elem);
		}
		
		else if (choice==2){
			y=Pop();
			printf("%d",y);
		}
		
		else if (choice==3){
			y=Peek();
			printf("%d",y);
		}
		
		else if (choice==4){
			Display();
		}
		
		else{
			printf("Invalid Choice");
		}
			
	}while (choice!=5);
	return 0;
}











