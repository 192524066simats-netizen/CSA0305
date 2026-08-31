#include <stdio.h>
#include <stdlib.h>
typedef struct Node{int data;struct Node*left,*right;}Node;
Node* newNode(int x){Node*n=malloc(sizeof(Node));n->data=x;n->left=n->right=NULL;return n;}
Node* insert(Node*r,int x){if(!r)return newNode(x);if(x<r->data)r->left=insert(r->left,x);else r->right=insert(r->right,x);return r;}
void inorder(Node*r){if(r){inorder(r->left);printf("%d ",r->data);inorder(r->right);}}
void preorder(Node*r){if(r){printf("%d ",r->data);preorder(r->left);preorder(r->right);}}
void postorder(Node*r){if(r){postorder(r->left);postorder(r->right);printf("%d ",r->data);}}
int main(){Node*r=NULL;int n,i,x;printf("Enter number of nodes: ");scanf("%d",&n);printf("Enter nodes:\n");for(i=0;i<n;i++){scanf("%d",&x);r=insert(r,x);}printf("Inorder: ");inorder(r);printf("\nPreorder: ");preorder(r);printf("\nPostorder: ");postorder(r);printf("\n");return 0;}