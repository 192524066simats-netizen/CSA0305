#include <stdio.h>
int main(){
    int a[100],n,i,pos,item,del;
    printf("Enter the number of elements: "); scanf("%d",&n);
    printf("Enter the elements:\n");
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    printf("Original Array:\n");
    for(i=0;i<n;i++) printf("%d ",a[i]); printf("\n");
    printf("Enter element to insert and position: "); scanf("%d%d",&item,&pos);
    if(pos<1||pos>n+1){printf("Invalid position.\n");return 0;}
    for(i=n;i>=pos;i--) a[i]=a[i-1];
    a[pos-1]=item; n++;
    printf("Array after insertion:\n");
    for(i=0;i<n;i++) printf("%d ",a[i]); printf("\n");
    printf("Enter position to delete: "); scanf("%d",&del);
    if(del<1||del>n){printf("Invalid position.\n");return 0;}
    for(i=del-1;i<n-1;i++) a[i]=a[i+1];
    n--;
    printf("Array after deletion:\n");
    for(i=0;i<n;i++) printf("%d ",a[i]); printf("\n");
    return 0;
}