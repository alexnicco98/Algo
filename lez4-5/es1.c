// Selection Sort su interi
#include <stdio.h>
#include <stdlib.h>

 void selection(int a[],int c){
      int i=0,j,d;
      for(i=0;i<c;i++){          
           for(j=0;j<c;j++){
                if(a[i]>a[j]){                   
                     d=a[i];
                     a[i]=a[j];
                     a[j]=d;
                }
           }
      }     
      for(i=c-1;i>=0;i--)
           printf("%d\n",a[i]);
   
 }
 
   int main(){
    int n,i=0;   
    scanf("%d",&n); 
    int a[n];   
    for(i=0;i<n;i++)
        scanf("%d",&a[i]); 
         
    selection(a,n);       
 
    return 0;
   }
