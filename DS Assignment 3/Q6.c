#include <stdio.h>
#define MaxWord 50

char Stack[MaxWord];
int top=-1,front=0;

void Push(char Elem){

	if(top>=(MaxWord)-1){
		printf("Stack Overflow");
		printf("\n");
	}
	
	else{
		Stack[++top]=Elem;
	}
}

char Pop(){
	if (top==-1){
		printf("Stack Underflow");
		printf("\n");
	}
	
	else{
		char x=Stack[top];
        --top;
		return x;
	}
}


int main(){

    char S[50],c;

    printf("Enter the String: ");
    scanf("%s",S);

    int i;
    
    for(i=0;S[i]!='\0';i++){
        c=S[i];
        Push(c);
    }

    int flag=1;

    while(top!=front){

        if (Stack[top]!=Stack[front]){
            flag=0;
            break;
        }

        else{
            --top;
            ++front;
        }
    }

    if (flag==1){
        printf("%s is a Palindrome",S);
    }

    else{
        printf("%s is not a Palindrome",S);
    }

    return 0;
}