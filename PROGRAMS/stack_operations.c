#include <stdio.h>
#define MAX 100
int main(){
    int stack[MAX],top=-1,choice,item,i;
    do{
        printf("\n1.Push 2.Pop 3.Peek 4.Display 5.Exit\nEnter choice: ");scanf("%d",&choice);
        if(choice==1){if(top==MAX-1)printf("Stack Overflow\n");else{printf("Enter item: ");scanf("%d",&item);stack[++top]=item;}}
        else if(choice==2){if(top==-1)printf("Stack Underflow\n");else printf("Deleted Element: %d\n",stack[top--]);}
        else if(choice==3){if(top==-1)printf("Stack is Empty\n");else printf("Top Element: %d\n",stack[top]);}
        else if(choice==4){if(top==-1)printf("Stack is Empty\n");else{printf("Stack Elements:\n");for(i=top;i>=0;i--)printf("%d\n",stack[i]);}}
    }while(choice!=5);
    return 0;
}