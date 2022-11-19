#include <stdio.h>
#define Max_Terms 10

int Stack[Max_Terms];
int Aux_Stack[Max_Terms];
int top1=-1,top2=-1;
int S;

//[3,1,5,2,10]

void Push(int elem){

    if (top1==Max_Terms-1){
        printf("\n");
        printf("Stack Overflow");
    }

    else{

        if (top1==-1){
            top1++;
            top2++;

            Stack[top1]=elem;
            Aux_Stack[top2]=elem;
            S=Stack[top1];
        }

        else{

            top1++;
            Stack[top1]=elem;

            if (Stack[top1]<S){
                top2++;
                S=Stack[top1];
                Aux_Stack[top2]=S;
                
            }

            else{
                top2++;
                Aux_Stack[top2]=S;
            }            
        }

    }

}


void Pop(){

    if (top1==-1){
        
        printf("Stack UnderFlow!");
        printf("\n");
    }

    else{

        int y;
        y=Stack[top1];
        printf("The Element popped out is %d",y);
        y=Stack[--top1];
        Aux_Stack[--top2];

    }
}

void GetMin(){
    if (top1==-1){
        printf("Stack Empty");
        printf("\n");
    }

    else{
        printf("The Minimum element in the Stack is %d",Aux_Stack[top2]);
        printf("\n");
    }
}

void Display(){

    int i;

    if (top1==-1){
        printf("The Stack is Empty");
        printf("\n");
    }

    else{

        for(i=top1;i>=0;i--){
            printf("%d",Stack[i]);
            printf("\n");
        }
    }
}


int main(){

    printf("\n");
    int c;

    do{
        
        printf("\n1.Push");
		printf("\n2.Pop");
		printf("\n3.Display Minimum Element");
		printf("\n4.Display all the Elements");
        printf("\n 5.Exit");

        printf("Choice: ");
        scanf("%d",&c);
        printf("\n");

        switch (c){

            case 1:
                int x;
                printf("Enter the Element you want to Add: ");
                scanf("%d",&x);
                Push(x);
                break;
            
            case 2:
                Pop();
                break;
            
            case 3:
                GetMin();
                break;

            case 4:
                Display();
                break;
            
            case 5:
                printf("Program Terminated!");
                break;

            default:
                printf("Invalid Choice!");
                break;
        }

    }while(c!=5);

    return 0;
}