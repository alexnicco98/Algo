// Si vuole implementare una rubrica telefonica, in cui 
// un record della rubrica è costituito da un nome (una
// stringa senza spazi, univoca) a cui `e associato
// un numero di telefono. Quando si inserisce un record 
// in una lista di trabocco, se vi sono conflitti il
// record va inserito in ordine lessicografico non 
// decrescente, scandendo opportunamente la lista fino
// ad individuare la posizione in cui inserirlo.
// Dato un intero K tale che 0 ≤ K < 2N , il programma
// deve stampare il  contenuto  della  lista  di
// trabocco  di  posizione K.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ele{
      char nome[101];
      char tele[21];
      struct ele *next;
};
typedef struct ele ElementoDiLista;
typedef ElementoDiLista *ListaDiElementi;

int hash(char *a,int dim){  // funzione hash
      int i=0;
      unsigned int som=0;
      while(a[i]){
             som+=a[i];
             i++;
      }
      return som%dim;
}

void insert();
void printoverflowlist();

int main(){
      int i,n,h,k;
      char *x=malloc(sizeof(char)*101),*val =malloc(sizeof(char)*21);
      scanf("%d",&n);
      int dim=n*2; 
      ListaDiElementi *lis =malloc(sizeof(ListaDiElementi)*dim);
      for(i=0;i<dim;i++)
            lis[i]=NULL;
      for(i=0;i<n;i++){
            scanf("%s",x);         
            scanf("%s",val);
            h=hash(x,dim);
            insert(&lis[h],x,val);
      }
      scanf("%d",&k);
      if(0<=k<dim)
            printoverflowlist(lis[k]);            
      return 0;
}

void insert(ListaDiElementi *l,char *x,char *val){
         int ok =1;
         ListaDiElementi aux=*l,new,prec=NULL;
         new =malloc(sizeof(ElementoDiLista));
         strcpy(new->nome,x);
         strcpy(new->tele,val);  
         new->next =NULL;
         if(aux==NULL){
              *l =new;
         } 
         else{
              while(aux !=NULL && ok){
                     if(strcmp(x,aux->nome)<=0)
                              if(prec==NULL){
                                     *l =new;
                                     new->next =aux;
                                     ok =0;
                              }
                              else{
                                     prec->next =new;
                                     new->next =aux;
                                     ok =0;
                              }
                      prec =aux;
                      aux =prec->next;
               }
               if(ok){
                    prec->next=new;
               }
         }
}

void printoverflowlist(ListaDiElementi l){
         while(l !=NULL){
                printf("%s %s\n",l->nome,l->tele);
                l =l->next;
         }
}




