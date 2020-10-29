// Il programma rappresenta un ambulatorio, ogni volta che entra 
// un paziente si inserisce in fondo alla lista, e quando viene 
// chiamato un paziente si elimina il primo dalla lista, quando
// arriviamo all'orario di chiusura si devono stampare in output
// i nomi di tutti i  pazienti  ancora  in  coda  in ordine  alfabetico.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Node structure:
struct elemento {
	char *info;
	struct elemento *next;
};

typedef struct elemento ElementoDiLista;
typedef  ElementoDiLista *ListaDiElementi;

void insert(ListaDiElementi *lis,char *a){
          ListaDiElementi new;
          new=malloc(sizeof(ElementoDiLista)); 
	  new->info= (char *) malloc(sizeof(char) * 101);
          strcpy(new->info,a);
          new->next=NULL;   
          if(*lis==NULL)
                *lis=new;
          else{  
                 ListaDiElementi aux=*lis;
                 while(aux->next!=NULL)
                        aux=aux->next;
                 aux->next=new;                 
          }
}

void delete(ListaDiElementi *lis){  // elimina dalla lista il primo paziente
         if(*lis!=NULL){
               ListaDiElementi aux=*lis;
               *lis=aux->next;
               free(aux);
         }
}

int scan(ListaDiElementi lis){     // retituisce la lunghezza della lista
        if(lis==NULL)  return 0;
        else  return (scan(lis->next))+1;
}

void copy(char **b,ListaDiElementi lis){ // copia i paziente in coda in un'array di stringhe
        int i=0;
        if(lis!=NULL){
              while(lis!=NULL){
                     b[i]=(char*)malloc(101*sizeof(char));
                     b[i]=lis->info;
                     lis=lis->next;
                     i++;
              }
        }
}

void stampa(ListaDiElementi lis){
        if(lis==NULL) 
               printf("NULL\n");
        else{
               printf("%s -> ",lis->info);
               stampa(lis->next);
        }    
}

void eliminalista(ListaDiElementi *lis){
        if(*lis!=NULL){
              eliminalista(&((*lis)->next));
              free(*lis);
        }
}

int compare(const void *a,const void *b){
        char **x=(char**) a,**y=(char**) b;
        return strcmp(*x,*y);
}

int main() {
        ListaDiElementi lis=NULL;
        int e=1,n,i,ok=1;
        char* a=(char*)malloc(101*sizeof(char));
        while(ok){
              scanf("%d",&e);
              if(e==1){
                      scanf("%s",a);
                      insert(&lis,a);
              }
              else if(e==2)              
                         delete(&lis);
                   else if(e==0){
                            n=scan(lis);
                            char **b=(char**)malloc(n*sizeof(char*));
                            copy(b,lis); 
                            eliminalista(&lis);
                            qsort(b,n,sizeof(char*),compare);  // ordiniamo i pazienti in ordine alfabetico
                            for(i=0;i<n;i++)     
                                  printf("%s\n",b[i]);                      
                            ok=0;    
                           }                       
         }         
        printf("$\n");                              
	return 0;
}
