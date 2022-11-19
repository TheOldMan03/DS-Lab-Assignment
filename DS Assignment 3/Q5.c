#include <stdio.h>
#define MaxTerms 50

int Stack[MaxTerms];
int top=-1;

void Push(int Element){

	if(top>=(MaxTerms)-1){
		printf("Stack Overflow");
		printf("\n");
	}
	
	else{
		Stack[++top]=Element;
	}
}

int Pop(){
	if (top==-1){
		printf("Stack Underflow");
		printf("\n");
	}
	
	else{
		int x=Stack[--top];
		return x;
	}
}

int main(){

    int N,r,x;
    printf("Enter the Decimal Number: ");
    scanf("%d",&N);

    x=N;

    int HexCounter=0;

    while(N!=0){

        r=N%2;
        Push(r);
        N=N/2;
    }

    int i,y;

    while(x!=0){

        r=x%16;
        Push(r);
        x=x/16;
        HexCounter++;
    }

    printf("HexaDecimal Representation\n");

    for(i=0;i<HexCounter;i++){

        y=Pop();

        switch (y){

        case 10:
            printf("A");
            break;
        
        case 11:
            printf("B");
            break;

        case 12:
            printf("C");
            break;
        
        case 13:
            printf("D");
            break;
        
        case 14:
            printf("E");
            break;
        
        case 15:
            printf("F");
            break;
        
        default:
            printf("%d",y);
        }
        
    }
    printf("\n");

    for(i=top;i>=0;i--){
        printf("%d",Stack[i]);
    }

}