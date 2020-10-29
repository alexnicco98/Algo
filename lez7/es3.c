/* Scrivere un programma che legga da tastiera una sequenza A
   di N stringhe di lunghezza variabile.Il programma deve poi
   raggruppare le stringhe di A aventi lo stesso anagramma principale
   e restituire le stringhe di ciascun gruppo in ordine lessicografico 
   non-decrescente. I gruppi devono essere restituiti in ordine 
   lessicografico non-decrescente del corrispondente anagramma
   principale.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct e{      /*struttura in cui mi salvo la stringa iniziale*/
       char* str;      /*e l'anagramma principale della stringa*/
       char* anagr;
}elem;

int compare(const void *a,const void *b){
      char *a1=(char*) a,*b1=(char*) b;
      return strcmp(a1,b1);
}

int conf(const void *a, const void *b){
     elem *a1=(elem*)a,*b1=(elem*)b;
     if(strcmp(a1->anagr,b1->anagr)==0) 
             return strcmp(a1->str,b1->str);
     return strcmp(a1->anagr,b1->anagr);
}

int main(){   
      int n,i,j=0,x;   
      scanf("%d",&n); 
      elem* a;  
      a=(elem*)malloc(n*sizeof(elem)); 
      for(i=0;i<n;i++){ 
            a[i].str=(char*)malloc(20*sizeof(char));  
            a[i].anagr=(char*)malloc(20*sizeof(char));          
            scanf("%s",a[i].str); 
            x=strlen(a[i].str);
            a[i].anagr=strcpy(a[i].anagr,a[i].str);
            qsort(a[i].anagr,x,sizeof(char),compare);  /*fa l'anagramma principale della stringa*/
      }    
      qsort(a,n,sizeof(elem),conf);       /*ordina le stringhe in base all'anagramma e se è uguale*/  
      for(i=0;i<n-1;i++)                  /*in base all' ordine lessicografico*/
            if(strcmp(a[i].anagr,a[i+1].anagr)==0)
                     printf("%s ",a[i].str);
            else
                     printf("%s\n",a[i].str);
      printf("%s\n",a[n-1].str);
   
      return 0;
      
}




