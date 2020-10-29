#include <stdio.h>
#include <string.h>

 char* my_strcpy(char *dest,char *src){
    int i=0,c;
    c=strlen(src);
    if(c>1000)
        return NULL;
    while(src[i]){ //src[i]!='\0'
        dest[i]=src[i];
        i++;
    }
    dest[i]='\0';
    return dest;
}
 
   int main(){
    char a[1001],b[1001];
    scanf("%s",a); 
    printf("%s\n",my_strcpy(b,a));
    return 0;
   }
