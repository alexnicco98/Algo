#include <stdio.h>
#include <stdlib.h>

 void insertion(int a[],int c){
      int i,j,key;
      for(i=1;i<c;i++){ 
           key=a[i]; 
           j=i-1;           
           while(j>=0&&a[j]>key){
                a[j+1]=a[j];
                j--;                                                       
           }
           a[j+1]=key;
      }     
      for(i=0;i<c;i++)
           printf("%d\n",a[i]);
   
 }
 
   int main(){
    int c,i=0;   
    scanf("%d",&c); 
    int a[c];   
    for(i=0;i<c;i++)
        scanf("%d",&a[i]); 
         
    insertion(a,c);       
 
    return 0;
   }
