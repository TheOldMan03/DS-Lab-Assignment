#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define Max_Size 50
int stack[Max_Size];
int top=-1;


void push(int element){
    if (top==Max_Size-1){
        printf("Stack Overflow\n");
    }
    else{
        stack[++top]=element;
    }
}


int pop(){
    if (top==-1){
        printf("Stack Under Flow\n");
    }
    else{
        int del= stack[top];
        top--;
        return del;
    }
}


int PostfixEval(char expression[]){

    int n1,n2,num;
    char ch;             

    int i=0;
    while (expression[i]!='\0'){
        ch=expression[i]; 
        if (isdigit(ch)){ 
            num=ch-'0';   
            push(num);
        }
        else{
            n1=pop();
            n2=pop();

            switch (ch){
            case '+':
                num=n1+n2;
                break;
            case '-':
                num=n2-n1;    
                break;
            case '*':
                num=n1*n2; 
                break;
            case '/':
                num=n2/n1;    
                break;
            case '^':
                num=n2^n1;    
                break;
            }
            push(num);
        }
        i++;
    }
    return pop();
}

int main(){
    
    char expression[Max_Size];
    printf("Enter the Postfix Expression: ");
    scanf("%s",expression);
    printf("The Result of the expression %s = ",expression);
    int x=PostfixEval(expression);
    printf("%d",x);
}