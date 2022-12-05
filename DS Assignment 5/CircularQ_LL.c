#include <stdio.h>
#include <stdlib.h>


struct Queue{
	int data;
	struct Queue* next;
};

struct Queue* rear=NULL;
struct Queue* front=NULL;

void Enqueue(int elem){

	struct Queue* newNode=malloc(sizeof(struct Queue)); //Creating a new Node

	if (rear==NULL){ //If Queue is empty
	
		newNode->data=elem;
		newNode->next=NULL;
		rear=newNode;
		front=newNode;
		
		printf("The element %d is successfully added",elem);
		printf("\n");
	}
	
	else{
		rear->next=newNode;
		rear=newNode;
		
		newNode->data=elem;
		newNode->next=front;
		
		printf("The element %d is successfully added",elem);
		printf("\n");
		
	}
}

void Dequeue(){

	if (front==NULL){

		printf("Queue Underflow");
		printf("\n");
	}
	
	else{
	
		if (front==rear && front!=NULL){
			printf("The element deleted is %d",front->data);
			free(front);
			front=NULL;
			rear=NULL;
		}
	
		else{
		
			struct Queue* temp;
			temp=front;
			
			printf("The element deleted is %d",front->data);
			
			front=front->next;
			rear->next=front;
			
			free(temp);
		}
	
	}
}

void Peek(){

	if (front==NULL){
		printf("The Queue is empty");
		printf("\n");
	}
	
	else{
		printf("The element in the front is %d",front->data);
		printf("\n");
	}

}

void Display(){
	
	if (front==NULL){
		printf("Queue Empty");
		printf("\n");
	}

	else if (front==rear &&front!=NULL){
		printf("%d",front->data);
		printf("\n");
	}
	
	else{
		struct Queue* ptr;
		ptr=front;
		
		while(ptr->next!=front){
			printf("%d->",ptr->data);
			ptr=ptr->next;
		}
		printf("%d",ptr->data);
	}
}


int main(){


	int choice;
	int elem;

	do{

		printf("\n1.Enqueue");
		printf("\n2.Dequeue");
		printf("\n3.Peek");
		printf("\n4.Display");
		printf("\n5.Exit");

		printf("\n\nChoice: ");
		scanf("%d",&choice);

		switch(choice){

			case 1:
				printf("Enter the Element you want to Enter: ");
				scanf("%d",&elem);
				Enqueue(elem);
				break;
			
			case 2:
				Dequeue();
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
