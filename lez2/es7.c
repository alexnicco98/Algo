#include <stdio.h>
#include <string.h>

char* my_strcat(char *s1,char *s2){
  int x=strlen(s2);
  if(strlen(s1)+x>=1001)
      return NULL;
  int i=0,j=0;
  while(s1[i])//s1[i]!='|0'
      i++;
  while(s2[j]){
     s1[i]=s2[j];
     i++;
     j++;
  }
  s1[i]='\0';
  return s1;
}

int main(void){
  char a[1001];
  char b[1001];
  scanf("%s",a);
  scanf("%s",b);
  char *s= my_strcat(a,b);
  printf("%s\n",s);
  return 0;
}
