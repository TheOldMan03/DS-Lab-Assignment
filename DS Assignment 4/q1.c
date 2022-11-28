#include <stdio.h>
#include <stdlib.h>


//Defining a Linked List

struct Node{
	int elem;
	struct Node* next;
};

struct Node* head=(struct Node*)malloc(sizeof(struct Node)); //For the 1st Node

struct Node* top,temp;
top=head;

void Push(int elem){
	//There is no case of Stack Overflow in the case of a Linked List

	if (top==head){
	
		top->elem=elem;
		top->next=NULL;
		top=NULL;
		
		printf("")
	}
	
	else{ //ie the only condition is top=NULL
		
		temp=(struct Node*)malloc(sizeof(struct Node));
		top=temp;
		top->elem=elem;
		top->next=NULL;
		top=NULL;
	}
	
}


