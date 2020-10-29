#include <stdio.h>
void swap(int *a,int *b){
  int c=*a;
  *a=*b;
  *b=c;
  printf("%d\n",*a);
  printf("%d\n",*b);
}

int main(void){
  int a,b;
  scanf("%d",&a);
  scanf("%d",&b);
  swap(&a,&b);
  return 0;
}
