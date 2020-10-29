#include <stdio.h>
void minmax(int a[],int dim,int *min,int *max){
  int x=a[0],y=a[0];
  for(int i=1;i<dim;i++){
     if(a[i]<x){
          x=a[i];
          *min=i;
     }
     if(a[i]>y){
          y=a[i];   
          *max=i;     
     }
  }
  printf("%d\n%d\n%d\n%d\n",*min,x,*max,y);
}

int main(void){
  int a[10];
  int min,max;
  for(int i=0;i<10;i++)
     scanf("%d",&a[i]);
  minmax(a,10,&min,&max);
  return 0;
}
