#include <stdio.h>
#include <stdlib.h>

int valass(int x){
       if(x<0)
             return -x;
       else
             return x;
}

int compare(const void* a,const void* b){
       int *x=(int*) a,*y=(int*) b;
       if(valass(*x)%2==0){
              if(valass(*y)%2==0)
                      return (*x-*y);
              else
                      return -1;
       }
       if(valass(*x)%2==1){
              if(valass(*y)%2==1)
                      return (*y-*x);
              else
                      return 1;
       }
}                

int main(){   
      int n,i,x;   
      scanf("%d",&n); 
      int a[n];  
      for(i=0;i<n;i++)              
            scanf("%d",&a[i]);
                      
      qsort(a,n,sizeof(int),compare);
      for(i=0;i<n;i++)              
            printf("%d\n",a[i]);                 
      return 0;
      
}
