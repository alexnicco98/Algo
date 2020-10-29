#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 void anagramma(unsigned char *s1,unsigned char *s2){
    int c[256], d[256]; 
    int e,f,i,uguali=1,g; 
    g=strlen(s1);  
    for(i=0;i<256;i++){    //inizializza gli array a 0
        c[i]=0; 
        d[i]=0;       
    }
    for(i=0;i<g;i++){    //questo for torna, l'incremento è giusto
        e=s1[i];
        c[e]++;                       
    }
     g=strlen(s2);  
     for(i=0;i<g;i++){   //questo for non torna l'incremento è sbagliato
        e=s2[i];
        d[e]++;         
    } 
    i=0;   
    while(i<256&&uguali){
        if(c[i]==d[i]) i++;
        else uguali=0;                      
    }
    printf("%d\n",uguali);
}
 
   int main(){
    unsigned char a[1000],b[1000];
    int g;
    scanf("%s",a); 
    scanf("%s",b); 
    
    if(strlen(a)==strlen(b))   
       anagramma(a,b);
    else
      printf("%d\n",0);
 
 
    return 0;
   }
