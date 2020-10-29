#include <stdio.h>
int sumdisp(int x){
  int som=0,c=1;
  for(int i=0;i<x;i++){
     som+=c;
     c+=2;
  }
  return som;
}

int main(void){
  int x,i=2,ok=1;
  scanf("%d",&x);
  printf("%d\n",sumdisp(x));
  return 0;
}
