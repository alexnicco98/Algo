#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 void my_strcmp(char *s1,char *s2){
    int e=0,i=0,c;
    char d='+';
    c=strlen(s1);
    while(c>0&&e==0){
        if(s1[i]==s2[i])
            i++;                
        else 
             if(s1[i]<s2[i]){
                 e=-1;
                 printf("%d\n",e);
             }
             else{
                e=1;
                printf("%c%d\n",d,e);
             }
        c--;
    }
    if(e==0) printf("%d\n",e);
}
 
   int main(){
    char a[1000],b[1000];
    scanf("%s",a); 
    scanf("%s",b); 
    
    my_strcmp(a,b);
 
 
    return 0;
   }
