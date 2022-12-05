#include <stdio.h>
#define MaxTerms 10

int Queue[MaxTerms];
int front=-1,rear=-1;

void Enqueue(int elem){
	if (rear==MaxTerms-1){
		printf("Queue Overflow");
		printf("\n");
	}
	
	else if (front==-1){ //Stack Empty
		++front;
		Queue[++rear]=elem;
		printf("The element %d is Enqueued into Queue",elem);
		printf("\n");
	}
	
	else{
		Queue[++rear]=elem;
		printf("The element %d is Enqueued into Queue",elem);
		printf("\n");
	}
}

void Dequeue(){
	
	if (front==-1){
		printf("Queue Underflow");
		printf("\n");
		
	}
	
	else if (front==rear && front!=-1){
		
		printf("The deleted element is %d",Queue[front]);
		printf("\n");	
		front=-1;
		rear=-1;	
	}
	
	else{
	
		printf("The deleted element is %d",Queue[front++]);
		printf("\n");
	}	
}


void Peek(){
	
	if (front==-1){
		printf("The Queue is empty");
		printf("\n");
	}
	
	else{
		printf("The front element is %d",Queue[front]);
		printf("\n");
		
	}
}


void Display(){

	if (front==-1){
		printf("Queue Empty");
		printf("\n");
	}
	
	else{
		int i;
		
		for(i=front;i<=rear;i++){
			printf("%d",Queue[i]);
			printf("\n");
		}
		printf("\n");
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
