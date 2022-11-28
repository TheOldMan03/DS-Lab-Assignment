#include <stdio.h>
#include <stdlib.h>


//Defining a Linked List

struct Node{
	int elem;
	struct Node* next;
};

int main(){
	
	struct Node* head; //Head is a pointer which points to the 1st Node of the LinkedList
	//And it is type: Pointer of struct
	
	head=(struct Node*)malloc(sizeof(struct Node));
	
	
	if (head==NULL){
		printf("Memory insufficient!");
	}
	
	else{
		
		struct Node* ptr;
		struct Node* temp;
		
		int n;
		printf("Enter the total Number of elements you want to add in the List: ");
		scanf("%d",&n);
		
		int i;
		int data;
		
		ptr=head; //Initially let head=1000
		
		int elem;
		
		for(i=0;i<n-1;i++){
			printf("Enter the element you want to add in the List: ");
			scanf("%d",&elem);
			
			
			temp=(struct Node*)malloc(sizeof(struct Node)); //The Next Node,say 2000
			
			ptr->elem=elem;
			ptr->next=temp;
			
			ptr=temp;
			
		}
		
		printf("Enter the element you want to add in the List: ");
		scanf("%d",&elem);
		
		ptr->elem=elem;
		ptr->next=NULL;
		
		//For the last element
		
		ptr=head;
	
		while(ptr->next!=NULL){
			printf("%d->",ptr->elem);
			ptr=ptr->next;
		}
		
		printf("%d",ptr->elem);
			
	}	
}


