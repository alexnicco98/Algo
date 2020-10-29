#include <stdio.h>

int main(void){
int x,i,b;
scanf("%d",&x);
int a[x];
for(i=0;i<x;i++){
   scanf("%d",&b);
   a[i]=b;
}

for(i=0;i<x;i++)
   printf("%d\n",a[i]);
return 0;
}
