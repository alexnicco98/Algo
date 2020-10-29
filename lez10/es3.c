// Scrivere un programma che legga da tastiera una sequenza di
// n interi distinti e li inserisca in una lista monodirezionale. 
// Successivamente il programma deve  calcolare  la  media  aritmetica
//  dei  valori  della  lista  ed  eliminare  tutti gli elementi il 
// cui valore `e inferiore o uguale alla media, troncata all’intero
// inferiore.
#include <stdio.h>
#include <stdlib.h>

struct el{
    int info;
    struct el *next;
};

typedef struct el ElementoDiLista;
typedef ElementoDiLista *ListaDiElementi;

void filtra();
void insert();
void printlist();

int main(){
      int n,i,x,media=0;
      scanf("%d",&n);
      ListaDiElementi lis=NULL;
      for(i=0;i<n;i++){
            scanf("%d",&x);
            insert(&lis,x);
            media+=x;
      }
      media=media/n;
      printf("%d\n",media);
      printlist(lis);
      printf("\n");
      filtra(&lis,media);
      printlist(lis);
      printf("\n");

}

void delete(ListaDiElementi *l,int x){    // elimina l'elemento con campo info=x
      ListaDiElementi aux=*l,prec=NULL;   
      while(aux->info!=x){
              prec=aux;
              aux=aux->next;
              }
      prec->next=aux->next;
      free(aux);        
}

void filtra(ListaDiElementi *l,int media){  // elimina dalla lista gli elementi sotto 
      ListaDiElementi aux=*l;               // o uguali alla media
      while(aux!=NULL){
              while((*l)->info <=media){
                    *l=(*l)->next;
                    free(aux);
                    aux=*l;
              }
              if(aux->info <= media)
                    delete(l,aux->info);
              aux=aux->next;
      }
}

void insert(ListaDiElementi *l,int x){
      ListaDiElementi aux=*l,new;
      new=(ListaDiElementi) malloc(sizeof(ElementoDiLista));
      new->info=x;
      new->next=NULL;
      if(*l==NULL)
            *l=new;
      else{
            while(aux->next!=NULL)
                    aux=aux->next;
            aux->next=new;
     }
}

void printlist(ListaDiElementi l){
       if(l==NULL) return ;
       else {
            printf("%d ",l->info);
            printlist(l->next);
       }
}



