// K stringhe più frequenti
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int maxi(int x[],int n){  //trova il massimo elemento nell'array
       int m,i,new;
            m=x[0];
            new=0;
            for(i=1;i<n;i++){
                   if(x[i]>m){
                         m=x[i];
                         new=i;
                   } 
            }
            x[new]=1;                   
       return new;
}        

int compare(const void *a, const void *b){
      char **x=(char**)a, **y=(char**)b;
      return strcmp(*x,*y);
}   
 
void kfre(char** a,int k,int n){
   if(k!=0){ 
      int i=0,j,y[n],m,b;
      char** x;
      for(i=0;i<n;i++)                     //inizz.  array y
            y[i]=1;            
      x=(char**)malloc(k*sizeof(char*));   //puntatore a puntatori 
      for(i=0;i<k;i++)                     //inizz. array di stringhe della soluzione
           x[i]=(char*)malloc(101*sizeof(char));
      for(i=0;i<n-1;i++){                  //conteggio stringhe uguali
           if(strcmp(a[i],a[i+1])==0){
                  j=i;
                  y[j]++;
                  i++; 
                  while(i<n-1&&strcmp(a[i],a[i+1])==0){                              
                         y[j]++;
                         i++;                         
                 }                                    
           }          
      }
      for(i=0;i<k;i++){
            m=maxi(y,n);
            x[i]=a[m];            
      }
      qsort(x,k,sizeof(char *),compare);     
      for(i=0;i<k;i++)
           printf("%s\n",x[i]);       
  }
}  
          

int main(){   
      int n,k,i;   
      scanf("%d",&n); 
      scanf("%d",&k);
      char** a;  
      a=(char**)malloc(n*sizeof(char*)); 
      for(i=0;i<n;i++){ 
            a[i]=(char*)malloc(101*sizeof(char));           
            scanf("%s",a[i]); 
      }      
      qsort(a,n,sizeof(char *),compare);              
      kfre(a,k,n);
      return 0;
      
}
