
#include <stdio.h>


int tswap(int *x, int *y, int *z){

int a,b;
a=*x;
*x=*z;
b=*y;
*y=a;
*z=b;
}

int main(void){
int x,i;
int a[3];
for(i=0;i<3;i++){
   scanf("%d",&x);
   a[i]=x;
}

tswap(&a[0],&a[1],&a[2]);

for(i=0;i<3;i++)
   printf("%d\n",a[i]);
return 0;
}


