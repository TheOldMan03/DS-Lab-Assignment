#include <stdio.h>
#define MaxTerms 10

int Queue[MaxTerms];
int front=-1;
int rear=-1;

void Enqueue(int elem){

    if (front==-1){ //Only 1 element in the list
        front++;
        rear++;

        Queue[rear]=elem;
        printf("Element %d is successfully added!\n",elem);
    }

    else{
        rear=(rear+1)%MaxTerms;

        if (front==rear){
            printf("Queue Overflow\n");
        }

        else{
            Queue[rear]=elem;
            printf("Element %d is successfully added!\n",elem);
        }

    }
}

void Dequeue(){

    int x;
    

    if (front==-1){
        printf("Queue Underflow\n");
    }

    else{

        x=Queue[front];

        if (front==rear && front!=-1){
            printf("Element Dequeued is %d\n",x);
            
            front=-1;
            rear=-1;
        }

        else{
            printf("Element Dequeued is %d\n",x);
            front=(front+1)%MaxTerms;
        }
    }

}

void Peek(){

    if (front==-1){
        printf("Queue Empty\n");
    }

    else{
        printf("%d\n",Queue[rear]);
    }

}

void Display(){

    int i;

    if (front==-1){
        printf("Queue is Empty\n");
    }

    else{

        for(i=front;i<=rear;i++){
            printf("%d",Queue[i]);
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