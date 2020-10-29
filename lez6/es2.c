// Qsort su stringhe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int compare(const void* a,const void* b){
       char **x=(char**) a,**y=(char**) b;
       return strcmp(*y,*x);
}                

int main(){   
      int n,i,x;   
      scanf("%d",&n); 
      char **a=malloc(sizeof(char**)*n);  
      for(i=0;i<n;i++){  
            a[i]=malloc(sizeof(char)*101);            
            scanf("%s",a[i]); 
      }                  
      qsort(a,n,sizeof(char*),compare);
      for(i=0;i<n;i++)              
            printf("%s\n",a[i]);           
      
      return 0;
      
}
