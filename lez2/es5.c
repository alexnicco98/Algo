#include <stdio.h>
#include <stdlib.h>


 char* mystrcat1(char *s1, char *s2){
    
    printf("%s%s\n",s1,s2);
}
 
   int main(){
    char a[1000],b[1000];
    scanf("%s",a); 
    scanf("%s",b); 

    mystrcat1(a,b);
    
 
 
    return 0;
   }
