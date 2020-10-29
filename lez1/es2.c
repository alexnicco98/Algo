#include <stdio.h>

int main(void){
  int x,i=2,ok=1;
  scanf("%d",&x);
  while(ok&&i<x){
     if(x%i==0)
         ok=0;
     i++;
  }  
  printf("%d\n",ok);
  return 0;
}
