#include <stdio.h>
#define MAX 100
int main(){
    int table[MAX],m,n,i,key,index,count;
    printf("Enter hash table size: ");scanf("%d",&m);
    for(i=0;i<m;i++)table[i]=-1;
    printf("Enter number of keys: ");scanf("%d",&n);
    if(n>m){printf("Too many keys for table size.\n");return 0;}
    printf("Enter keys:\n");
    for(i=0;i<n;i++){
        scanf("%d",&key);index=key%m;count=0;
        while(table[index]!=-1&&count<m){index=(index+1)%m;count++;}
        if(count<m)table[index]=key;else printf("Hash table full\n");
    }
    printf("Hash Table:\n");
    for(i=0;i<m;i++)printf("Index %d : %d\n",i,table[i]);
    return 0;
}