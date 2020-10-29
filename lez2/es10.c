#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 void product(char *str,int k){
    char c[1000];
    c[0]=0;
    while(k>0){
       strcat(c,str);
       k--;
    }
    printf("%s\n",c);
   
}
 
   int main(){
    char a[1000];
    int b;
    scanf("%s",a); 
    scanf("%d",&b); 
                
      //printf("%s\n",product(a,b));
    product(a,b);
 
    return 0;
   }
