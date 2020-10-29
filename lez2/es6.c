#include <stdio.h>
#include <stdlib.h>
#include <string.h>


 char* mystrcat2(char *s1, char *s2,int s){ // s "mi sa" non serve
    char c[s];
    c[0]=0;
    strcat(c,s1);
    strcat(c,s2);
    printf("%s\n",c);
}
 
   int main(){
    int s,i,j;
    scanf("%d",&i);
    char a[i]; 
    scanf("%s",a); 
    scanf("%d",&j);
    char b[j]; 
    scanf("%s",b); 

    s=i+j;
    mystrcat2(a,b,s);
    
 
 
    return 0;
   }
