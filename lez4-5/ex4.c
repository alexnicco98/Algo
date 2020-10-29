#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Ricbin(char **string,char *new,int i,int j){
       int m,x;
       if(j<i) return -1;
       else{
            m=(i+j)/2;
            x=strcmp(string[m],new);
            if(x==0)  return m;
            if(x>0) 
                     Ricbin(string,new,i,m-1);
            else
                     Ricbin(string,new,m+1,j);
       }
}      

int main(){   
      int n,i,x,m;   
      scanf("%d",&n); 
      char **a= malloc(sizeof(char [101])*n);
      char new[101];  
      for(i=0;i<n;i++){     
            a[i]=malloc(sizeof(char [101]));      
            scanf("%s",a[i]);  
      }   
      scanf("%d",&x);       
      while(x==1){
           scanf("%s",new);                  
           m=Ricbin(a,new,0,n-1);                  
           printf("%d\n",m);                                 
           scanf("%d",&x);  
      }     

      return 0;
      
}
