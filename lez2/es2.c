


#include <stdio.h>

void reset(int a[], int len){  // inizializza l’array dei contatori a 0
    int i;
    for(i=0;i<len;i++)
        a[i]=0;
}

void add(int a[], int len, int val){ //incrementa  il  contatore array[val] se val `e tra 0 e len-1
   int i;
   for(i=0;i<len;i++){   
      if(val==i)
      a[i]++;
   }
}

int main(void){
int x=0,i;
int a[10];
reset(a,10);
while(x!=-1){
   scanf("%d",&x);
   if(0<=x<=10)
      add(a,10,x);
}

for(i=0;i<10;i++)
   printf("%d\n",a[i]);
return 0;
}




