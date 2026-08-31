#include <stdio.h>
#include <stdlib.h>
typedef struct Node{int key,height;struct Node*l,*r;}Node;
int h(Node*n){return n?n->height:0;} int max(int a,int b){return a>b?a:b;}
Node* nn(int k){Node*n=malloc(sizeof(Node));n->key=k;n->height=1;n->l=n->r=NULL;return n;}
Node* rightRotate(Node*y){Node*x=y->l,*t=x->r;x->r=y;y->l=t;y->height=1+max(h(y->l),h(y->r));x->height=1+max(h(x->l),h(x->r));return x;}
Node* leftRotate(Node*x){Node*y=x->r,*t=y->l;y->l=x;x->r=t;x->height=1+max(h(x->l),h(x->r));y->height=1+max(h(y->l),h(y->r));return y;}
int bal(Node*n){return n?h(n->l)-h(n->r):0;}
Node* insert(Node*n,int k){if(!n)return nn(k);if(k<n->key)n->l=insert(n->l,k);else if(k>n->key)n->r=insert(n->r,k);else return n;n->height=1+max(h(n->l),h(n->r));int b=bal(n);if(b>1&&k<n->l->key)return rightRotate(n);if(b<-1&&k>n->r->key)return leftRotate(n);if(b>1&&k>n->l->key){n->l=leftRotate(n->l);return rightRotate(n);}if(b<-1&&k<n->r->key){n->r=rightRotate(n->r);return leftRotate(n);}return n;}
Node* minNode(Node*n){while(n->l)n=n->l;return n;}
Node* del(Node*r,int k){if(!r)return r;if(k<r->key)r->l=del(r->l,k);else if(k>r->key)r->r=del(r->r,k);else{if(!r->l||!r->r){Node*t=r->l?r->l:r->r;if(!t){free(r);return NULL;}*r=*t;free(t);}else{Node*t=minNode(r->r);r->key=t->key;r->r=del(r->r,t->key);}}r->height=1+max(h(r->l),h(r->r));int b=bal(r);if(b>1&&bal(r->l)>=0)return rightRotate(r);if(b>1&&bal(r->l)<0){r->l=leftRotate(r->l);return rightRotate(r);}if(b<-1&&bal(r->r)<=0)return leftRotate(r);if(b<-1&&bal(r->r)>0){r->r=rightRotate(r->r);return leftRotate(r);}return r;}
int search(Node*r,int k){if(!r)return 0;if(r->key==k)return 1;return k<r->key?search(r->l,k):search(r->r,k);}
void inorder(Node*r){if(r){inorder(r->l);printf("%d ",r->key);inorder(r->r);}}
int main(){Node*r=NULL;int n,i,x,d,s;printf("Enter number of nodes: ");scanf("%d",&n);printf("Enter elements:\n");for(i=0;i<n;i++){scanf("%d",&x);r=insert(r,x);}printf("AVL Inorder: ");inorder(r);printf("\nEnter element to delete: ");scanf("%d",&d);r=del(r,d);printf("After deletion: ");inorder(r);printf("\nEnter element to search: ");scanf("%d",&s);printf(search(r,s)?"Element found\n":"Element not found\n");return 0;}