// Qsort su stringhe e struct
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct str{
       char x[101];
       int len;
}typedef string;

int compare(const void* a,const void* b){  // le stringhe sono ordinate per lunghezza crescente,
       string *c=(string*) a;              // a parità di lunghezza per ordine lessicografico
       string *d=(string*) b;
       if(c->len==d->len)              
              return strcmp(c->x,d->x); 
       else
              return (c->len-d->len); 
  
}             

int main(void){  
      int n,i;   
      scanf("%d",&n); 
      string a[n];  
      for(i=0;i<n;i++){                                 
                  scanf("%s",a[i].x);
                  a[i].len=strlen(a[i].x);
      }
                                         
      qsort(a,n,sizeof(string),compare);
      for(i=0;i<n;i++)                
            printf("%s\n",a[i].x);   
            
      return 0;
      
}
