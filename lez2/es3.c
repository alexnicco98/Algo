#include <stdio.h>
#include <stdlib.h>

int my_strlen(char *s){
  int i=0,len=0;
  while(s[i]!='\0'){
      len++;
      i++;
  }
  return len;
}

int main(void){
  char s[1001];
  scanf("%s",s);
  int len=my_strlen(s);
  printf("%d\n",len);
  return 0;
}
