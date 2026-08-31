#include <stdio.h>
#include <stdlib.h>
typedef struct Node{int data;struct Node*next;}Node;
Node* create(int x){Node*n=(Node*)malloc(sizeof(Node));n->data=x;n->next=NULL;return n;}
void display(Node*h){while(h){printf("%d",h->data);if(h->next)printf(" -> ");h=h->next;}printf("\n");}
int main(){
    Node*head=NULL,*tail=NULL,*p,*q; int n,i,x,pos,del;
    printf("Enter number of nodes: ");scanf("%d",&n);
    printf("Enter node values:\n");
    for(i=0;i<n;i++){scanf("%d",&x);p=create(x);if(!head)head=tail=p;else{tail->next=p;tail=p;}}
    printf("Original Linked List:\n");display(head);
    printf("Enter element and position to insert: ");scanf("%d%d",&x,&pos);
    if(pos<1||pos>n+1){printf("Invalid position.\n");return 0;}
    p=create(x);
    if(pos==1){p->next=head;head=p;}
    else{q=head;for(i=1;i<pos-1;i++)q=q->next;p->next=q->next;q->next=p;}
    n++; printf("After Insertion:\n");display(head);
    printf("Enter position to delete: ");scanf("%d",&del);
    if(del<1||del>n){printf("Invalid position.\n");return 0;}
    if(del==1){p=head;head=head->next;free(p);}
    else{q=head;for(i=1;i<del-1;i++)q=q->next;p=q->next;q->next=p->next;free(p);}
    n--; printf("After Deletion:\n");display(head);
    return 0;
}