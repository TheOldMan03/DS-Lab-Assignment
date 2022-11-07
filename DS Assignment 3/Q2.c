#include <stdio.h>
#define sizeMax 20

int Stack[sizeMax];
int top1=-1;
int top2=sizeMax;

void StackOperations(int);

void Push(int elem,int choiceOption,int top){
	
	if (choiceOption==1){
		
		if (top==(sizeMax/2)-1){
			printf("Stack overflow!");
			StackOperations(choiceOption);
		}
		
		else{
			Stack[++top]=elem;
			printf("Element %d successfully added!",elem);
			printf("\n");
			StackOperations(choiceOption);
			
		}	
	}
	
	if (choiceOption==2){
		
		if (top==sizeMax/2){
			printf("Stack Overflow!");
			StackOperations(choiceOption);
		}
		
		else{
			Stack[--top]=elem;
			printf("Element %d successfully added!",elem);
			printf("\n");
			StackOperations(choiceOption);
		}
		
	}
		
}

void Pop(int top,int choiceOption){

	if (choiceOption==1){
		
		if (top==-1){
			printf("Stack Underflow!");
			printf("\n");
			StackOperations(choiceOption);
		}
		
		else{
			int y;
			y=Stack[--top];
			printf("The Element %d is Popped out of the Stack",y);
			printf("\n");
			StackOperations(choiceOption);
		}	
	}
	
	else{
		
		if (top==sizeMax){
			printf("Stack Underflow!");
			printf("\n");
			StackOperations(choiceOption);
		}
		
		else{
			int y;
			y=Stack[++top];
			printf("The element %d is popped out of the stack",y);
			printf("\n");
			StackOperations(choiceOption);
		}	
	}
}

void Peek(int top,int choiceOption){

	int i;
	
	if (choiceOption==1){
	
		if(top==-1){
			printf("The Stack is Empty!");
			StackOperations(choiceOption);
		}
		
		else{
			printf("%d",Stack[top]);
			StackOperations(choiceOption);
			
		}	
	}
	
	else{
		
		if (top==sizeMax){
			printf("The Stack is Empty!");
			StackOperations(choiceOption);
		}
		
		else{
			printf("%d",Stack[top]);
			StackOperations(choiceOption);
		}
		
				
	}	
}

void Display(int top,int choiceOption){


	int i;
	
	if (choiceOption==1){
		
		if (top==-1){
			printf("The Stack is Empty");
			StackOperations(choiceOption);
		}
		
		else{
		
			for(i=0;i<top;i++){
				printf("%d",Stack[top]);
				printf("\n");
			}
			
			printf("\n");
			StackOperations(choiceOption);
			
		}	
	}
	
	else{
	
		if (top==sizeMax){
			printf("The Stack is Empty");
			StackOperations(choiceOption);
		}
		
		else{
		
			for(i=sizeMax-1;i>=top;i--){
				printf("%d",Stack[i]);
			}
			
			printf("\n");
			StackOperations(choiceOption);			
		}
	}
}


int StackSelection(){
	
	printf("\n");
	
	int c;
	
	printf("\n1.Stack1");
	printf("\n2.Stack2");
	printf("\n3.Exit");

	printf("Choose the stack you want to do the Operations on: ");
	scanf("%d",&c);
	
	if (c==3){
		return 0;
	}
	
	else if (c>3 || c<0){
		printf("Invalid Choice!");
	}
	
	else{
		StackOperations(c);
	}
}

void StackOperations(int c){

	int c1;
	
	do{
		printf("\n1.Push");
		printf("\n2.Pop");
		printf("\n3.Peek");
		printf("\n4.Display");
		printf("\n5.Return to Another Stack ");
		
		printf("\n");
		printf("Select your choice: ");
		scanf("%d",&c1);
		
		if (c1==1){//Pushing an element to the stack
			int x;
			printf("Enter the Element you want to Push: ");
			scanf("%d",&x);
			
			if (c==1){
				Push(x,c,top1);
			}
			
			else{
				Push(x,c,top2);
			}
		}
		
		else if (c1==2){
		
			if (c==1){
				Pop(top1,c);
			}
			
			else{
				Pop(top2,c);
			}
		}
		
		else if (c1==3){
			
			if (c==1){
				Peek(top1,c);
			}
			
			else{
				Peek(top2,c);
			}
		}
		
		else if (c1==4){
			
			if (c==1){
				Display(top1,c);
			}
			
			else{
				Display(top2,c);
			}
		}
		
		else if (c1==5){
			
			StackSelection();
		}
			
		else{
			printf("Invalid Choice");
		}
	
	}while(c1!=5);
}	


int main(){
	StackSelection();
}
