// Insertion Sort su stringhe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 void insertion(char **a,int c){
      int i,j,d;
      char* key;
      for(i=1;i<c;i++){ 
           key=a[i];            
           j=i-1;                    
           while(j>=0&&strcmp(a[j],key)>0){
                a[j+1]=a[j];
                j--;                                                       
           }
           a[j+1]=key;
      }     
      for(i=0;i<c;i++)
           printf("%s\n",a[i]);
      for(i=0;i<c;i++)
           free(a[i]);
      free (a);
   
 }
 
   int main(void){
    int n,i=0;   
    scanf("%d",&n); 
    char **a;
    a=(char**)malloc(n*sizeof(char*));
    for(i=0;i<n;i++){
        a[i]=(char*)malloc(101*sizeof(char));
        scanf("%s",a[i]);
        }
         
    insertion(a,n);     
 
    return 0;
   }
