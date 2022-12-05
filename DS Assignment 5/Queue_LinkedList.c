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
		
		rear->next=newNode; //Linking
		newNode->data=elem;
		newNode->next=NULL;
		rear=newNode;
		
		printf("The element %d is successfully added",elem);
		printf("\n");
		
	}
	
	
}

void Dequeue(){
	
	if (front==NULL){ //Queue is empty
		printf("Queue underflow");
		printf("\n");
	}
	
	else{
		
		struct Queue* temp;
		temp=front;
		printf("The Dequeued Element is %d",temp->data);
		printf("\n");
		front=front->next;
		free(temp);
		
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
	
	else{
		struct Queue* ptr;
		ptr=front;
		
		while(ptr->next!=NULL){
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

	


