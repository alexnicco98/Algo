#include <stdio.h>

int main(void){
int x,i,b,c=0;
scanf("%d",&x);
int a[x];
for(i=0;i<x;i++){
   scanf("%d",&b);
   a[i]=b;
}
for(i=x-1;i!=c&&i>c;i--){
    b=a[i];
    a[i]=a[c];
    a[c]=b;
    c++;
}
for(i=0;i<x;i++)
   printf("%d\n",a[i]);
return 0;
}
