#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 100
char stack[MAX]; int top=-1;
int prec(char c){if(c=='+'||c=='-')return 1;if(c=='*'||c=='/'||c=='%')return 2;if(c=='^')return 3;return 0;}
int main(){
    char infix[MAX],postfix[MAX]; int i=0,j=0; char c;
    printf("Enter the infix expression: ");scanf("%s",infix);
    while((c=infix[i++])!='\0'){
        if(isalnum((unsigned char)c)) postfix[j++]=c;
        else if(c=='(') stack[++top]=c;
        else if(c==')'){while(top>=0&&stack[top]!='(')postfix[j++]=stack[top--];if(top>=0)top--;}
        else{while(top>=0&&stack[top]!='('&&prec(stack[top])>=prec(c))postfix[j++]=stack[top--];stack[++top]=c;}
    }
    while(top>=0)postfix[j++]=stack[top--];
    postfix[j]='\0';
    printf("Postfix Expression: %s\n",postfix);
    return 0;
}