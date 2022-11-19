#include <stdio.h>
#define sizeMax 20

int Stack[sizeMax];
int top1=-1;
int top2=sizeMax;
int c=1; //The choice for selecting which stack is by Default the 1st one

void StackOperations();

void Push(int elem,int choiceOption){
	
	if (choiceOption==1){
		
		if (top1==(sizeMax/2)-1){
			printf("Stack overflow!");
			StackOperations(choiceOption);
		}
		
		else{
			Stack[++top1]=elem;
			printf("Element %d successfully added!",elem);
			printf("\n");
			StackOperations(choiceOption);
			
		}	
	}
	
	if (choiceOption==2){
		
		if (top2==sizeMax/2){
			printf("Stack Overflow!");
			StackOperations(choiceOption);
		}
		
		else{
			Stack[--top2]=elem;
			printf("Element %d successfully added!",elem);
			printf("\n");
			StackOperations(choiceOption);
		}
		
	}
		
}

void Pop(int choiceOption){

	if (choiceOption==1){
		
		if (top1==-1){
			printf("Stack Underflow!");
			printf("\n");
			StackOperations(choiceOption);
		}
		
		else{
			int y;
			y=Stack[top1];
			printf("The Element %d is Popped out of the Stack",y);
			y=Stack[top1--];
			printf("\n");
			StackOperations(choiceOption);
		}	
	}
	
	else{
		
		if (top2==sizeMax){
			printf("Stack Underflow!");
			printf("\n");
			StackOperations(choiceOption);
		}
		
		else{
			int y;
			y=Stack[top2];
			printf("The element %d is popped out of the stack",y);
			y=Stack[top2++];
			printf("\n");
			StackOperations(choiceOption);
		}	
	}
}

void Peek(int choiceOption){

	int i;
	
	if (choiceOption==1){
	
		if(top1==-1){
			printf("The Stack is Empty!");
			printf("\n");
			StackOperations(choiceOption);
		}
		
		else{
			printf("%d",Stack[top1]);
			printf("\n");
			StackOperations(choiceOption);
			
		}	
	}
	
	else{
		
		if (top2==sizeMax){
			printf("The Stack is Empty!");
			printf("\n");
			StackOperations(choiceOption);
		}
		
		else{
			printf("%d",Stack[top2]);
			printf("\n");
			StackOperations(choiceOption);
		}
		
				
	}	
}

void Display(int choiceOption){


	int i;
	
	if (choiceOption==1){
		
		if (top1==-1){
			printf("The Stack is Empty");
			StackOperations(choiceOption);
		}
		
		else{
		
			for(i=top1;i>=0;i--){
				printf("%d",Stack[i]);
				printf("\n");
			}
			
			printf("\n");
			StackOperations(choiceOption);
			
		}	
	}
	
	else{
	
		if (top2==sizeMax){
			printf("The Stack is Empty");
			printf("\n");
			StackOperations(choiceOption);
		}
		
		else{
		
			for(i=top2;i<=sizeMax-1;i++){
				printf("%d",Stack[i]);
				printf("\n");
			}
			
			printf("\n");
			StackOperations(choiceOption);			
		}
	}
}


void StackOperations(){

	int c1; //By Default uses the 1st Stack
	
	do{
		printf("\n1.Push");
		printf("\n2.Pop");
		printf("\n3.Peek");
		printf("\n4.Display");
		printf("\n5.Choose Another Stack ");
		printf("\n6.Exit");
		
		printf("\n");
		printf("Select your choice: ");
		scanf("%d",&c1);

		printf("\n");
		
		if (c1==1){//Pushing an element to the stack
			int x;
			printf("Enter the Element you want to Push: ");
			scanf("%d",&x);
			
			if (c==1){
				Push(x,c);
			}
			
			else{
				Push(x,c);
			}
		}
		
		else if (c1==2){
		
			if (c==1){
				Pop(c);
			}
			
			else{
				Pop(c);
			}
		}
		
		else if (c1==3){
			
			if (c==1){
				Peek(c);
			}
			
			else{
				Peek(c);
			}
		}
		
		else if (c1==4){
			
			if (c==1){
				Display(c);
			}
			
			else{
				Display(c);
			}
		}
		
		else if (c1==5){

			printf("\n1.Stack1");
			printf("\n2.Stack2");

			printf("\nChoose the stack you want to do the Operations on: ");
			scanf("%d",&c);

			if (c==1){
				printf("The Stack selected is the First One");
				printf("\n");
			}

			else if (c==2){
				printf("The Stack selected is the Second One");
				printf("\n");
			}

			else{
				printf("Invalid Choice!"); 
				printf("\n");
				//Here if User tries a silly Number it will go to its origin value
			}
			
		}

		else if (c1==6){
			printf("\nProgram Terminated!");
			break;
		}
			
		else{
			printf("Invalid Choice");
		}
	
	}while(c1!=6);
}	


int main(){
	StackOperations();
	return 0;
}
