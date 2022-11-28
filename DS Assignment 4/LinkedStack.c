#include <stdio.h>
#include <stdlib.h>

//Defining a Linked List

struct Node{
	int data;
	struct Node* next;
};


struct Node* top=NULL; //Initially there is nothing in the Stack

void Push(int elem){

	//No case for Stack Overflow unless there is insufficient Memory

	struct Node* newNode;
	newNode=malloc(sizeof(struct Node)); //Creating a Node Address

	if (top==NULL){  //If the list is empty
		top=newNode; 
		top->data=elem;
		top->next=NULL;

		printf("%d is successfully Added!",elem);
		printf("\n");
	}

	else{
		
		newNode->data=elem;
		newNode->next=top;
		top=newNode;

		printf("%d is successfully Added!",elem);
		printf("\n");
		
	}

}

void Pop(){

	if (top==NULL){
		printf("Stack Underflow");
		printf("\n");
	}

	else{
		struct Node* temp;

		temp=top;

		printf("%d is Popped out of the list",top->data);
		top=top->next;
		free(temp); //Memory Deallocated
	}

}

void Peek(){

	if (top==NULL){
		printf("The Stack is empty");
		printf("\n");
	}

	else{
		printf("%d is the topmost element of the Stack",top->data);
		printf("\n");
	}
}

void Display(){

	struct Node* ptr;
	ptr=top;

	if (ptr==NULL){
		printf("The Stack is empty");
		printf("\n");
	}

	else{

		while(ptr->next!=NULL){
			printf("%d->",ptr->data);
			ptr=ptr->next;
		}

		printf("%d",ptr->data); //For the last element

	}
}

int main(){

	int choice;

	do{

		printf("\n1.Push");
		printf("\n2.Pop");
		printf("\n3.Peek");
		printf("\n4.Display");
		printf("\n5.Exit");

		printf("\n\nChoice: ");
		scanf("%d",&choice);

		switch(choice){

			case 1:
				int elem;
				printf("Enter the Element you want to Push: ");
				scanf("%d",&elem);
				Push(elem);
				break;
			
			case 2:
				Pop();
				break;
			
			case 3:
				Peek();
				break;
			
			case 4:
				Display();
				break;
			
			case 5:
				printf("Program terminated!\n");
				break;
			
			default:
				printf("Invalid Choice!");
		}

	}while(choice!=5);

}
