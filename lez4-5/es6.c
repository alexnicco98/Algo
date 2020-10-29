#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char** a,int i,int j){
       char x[101];
       strcpy(x,a[i]);
       strcpy(a[i],a[j]);
       strcpy(a[j],x);
}

int Partition(char** a,int p,int r){
       char x[101];
       int i=p-1,j,y;
       /*y=p+rand()%(r-p+1); 
       if(r!=y){
             swap(a,y,r);
       }*/
       strcpy(x,a[r]);       
       for(j=p;j<r;j++)
             if(strcmp(a[j],x)<=0){                    
                    i++;
                    swap(a,i,j);
             }
       swap(a,i+1,r);
       return i+1;
}

void Qsort(char** a,int p,int r){
       int q;
       if(p<r){      
            q=Partition(a,p,r);           
            Qsort(a,p,q-1);
            Qsort(a,q+1,r);
       }
}  
                

int main(){   
      int n,k,i,x;   
      scanf("%d",&n); 
      scanf("%d",&k);
      char** a;  
      a=(char**)malloc(n*sizeof(char*)); 
      for(i=0;i<n;i++){ 
            a[i]=(char*)malloc(101*sizeof(char));           
            scanf("%s",a[i]); 
      }     
      Qsort(a,0,n-1);
      for(i=0;i<n;i++)              
            printf("%s\n",a[i]);           
      
      return 0;
      
}
