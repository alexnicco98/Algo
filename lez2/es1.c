#include <stdio.h>
#include <stdlib.h>
int binarySearch(int a[],int k,int i, int j){
  int m;
  if(j<i) return -1;
  else
     m=(i+j)/2;
  if(a[m]==k) return m;
  if(a[m]>k) return binarySearch(a,k,i,m-1);
  else return binarySearch(a,k,m+1,j);
}
int cmpfun(const void *a,const void *b){
  return(*(int*)a-*(int*)b);
}
int* FindVal(int a[],int len,int val){
  qsort(a,len,sizeof(int),cmpfun);
  int k=binarySearch(a,val,0,len-1);
  if(k==-1) return NULL;
  int *x=&a[k];
  return x;
}

int main(void){
  int a[10];
  int val;
  for(int i=0;i<10;i++)
     scanf("%d",&a[i]);
  scanf("%d",&val);
  if(FindVal(a,10,val)==NULL) printf("non trovato\n");
  else printf("trovato\n");
  return 0;
}
