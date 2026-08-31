#include <stdio.h>
#define MAX 100
int main(){
    int q[MAX],front=-1,rear=-1,choice,item,i;
    do{
        printf("\n1.Enqueue 2.Dequeue 3.Front 4.Display 5.Exit\nEnter choice: ");scanf("%d",&choice);
        if(choice==1){
            if(rear==MAX-1)printf("Queue Overflow\n");
            else{printf("Enter item: ");scanf("%d",&item);if(front==-1)front=0;q[++rear]=item;}
        }else if(choice==2){
            if(front==-1||front>rear)printf("Queue Underflow\n");
            else{printf("Deleted Element: %d\n",q[front++]);if(front>rear)front=rear=-1;}
        }else if(choice==3){
            if(front==-1)printf("Queue is Empty\n");else printf("Front Element: %d\n",q[front]);
        }else if(choice==4){
            if(front==-1)printf("Queue is Empty\n");else{printf("Queue Elements:\n");for(i=front;i<=rear;i++)printf("%d ",q[i]);printf("\n");}
        }
    }while(choice!=5);
    return 0;
}