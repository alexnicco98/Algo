// Lo studente vuole minimizzare il numero di esami. 
// A parità di crediti per esame, vuole minimizzare 
// la difficoltà. Scrivere un programma che opera
// come segue:
// • si selezionano inizialmente gli esami con il 
// maggior numero di crediti; a parità di crediti, 
// si selezionano prima gli esami aventi difficoltà
// minore;  a parità di difficoltà, si selezionano 
// gli esami in base all’ordine lessicografico non 
// decrescente della sigla;
// • se  l’inserimento  di  un  esame  provoca  il 
// superamento  dei K crediti, viene scartato.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct el{
      char nome[101];
      int cfu;
      int hard;
      struct el* next;
};

typedef struct el ElementoDiLista;
typedef ElementoDiLista *ListaDiElementi;

void insert();  // inserisce gli esami ordinati in base a: maggior crediti
                // se uguali, in base alla difficoltà minore, se difficoltà
                // uguale, ordine lessicografico crescente

void organize();  
         // gli esami ordinati vengono inseriti in ordine lesssicografico
         // crescente in una lista, fino al raggiungimento dei k crediti

int main(){
      int cfu,dif,k,n;
      char *a= malloc(sizeof(char)*101);
      scanf("%d",&k);
      scanf("%d",&n);
      ListaDiElementi lis= NULL;
      for(int i=0;i<n;i++){
             scanf("%s",a);
             scanf("%d",&cfu);
             scanf("%d",&dif);
             insert(&lis, a, cfu, dif);
      }
      organize(lis,k);

      return 0;
}

void insert(ListaDiElementi *l, char *a, int cre, int dif){
      ListaDiElementi new= malloc(sizeof(ElementoDiLista));
      ListaDiElementi aux=*l, prec=NULL;
      int ok=1;
      strcpy(new->nome, a);
      new->cfu= cre;
      new->hard= dif;
      new->next= NULL;
      if(aux==NULL)
             *l= new;
      else{
             while(aux!=NULL && ok){
                    if(cre>aux->cfu){
                           if(prec==NULL){
                                  *l= new;
                                   new->next= aux;
                                   ok= 0;
                           }
                           else{
                                   prec->next= new;
                                   new->next= aux;
                                   ok= 0;
                           }
                    }
                    else if(cre==aux->cfu){ 
                               if(dif<aux->hard){
                                      if(prec==NULL){
                                              *l= new;
                                              new->next= aux;
                                              ok= 0;
                                      }
                                      else{
                                              prec->next= new;
                                              new->next= aux;
                                              ok= 0;
                                       }
                                }
                                else if(dif==aux->hard){
                                             if(strcmp(a, aux->nome)<=0){
                                                      if(prec==NULL){
                                                              *l= new;
                                                              new->next= aux;
                                                              ok= 0;
                                                       }
                                                       else{
                                                              prec->next= new;
                                                              new->next= aux;
                                                              ok= 0;
                                                       } 
                                              }  
                                     }
                         }
                    prec= aux;
                    aux= prec->next;     
             }
             if(ok)
                    prec->next= new;
        }
}

// Gli elementi vengono inseriti in ordine lessicografico
void insertfinal(ListaDiElementi *l,char *a, int cre, int dif){
       ListaDiElementi prec= NULL, aux= *l,new;
       int ok= 1;
       new=malloc(sizeof(ElementoDiLista));
       strcpy(new->nome, a);
       new->cfu= cre;
       new->hard= dif;
       new->next= NULL;              
       if(*l==NULL)
              *l= new;
       else{
              while(aux!= NULL && ok){
                   if(strcmp(new->nome, aux->nome)<=0){
                           if(prec==NULL){
                                 *l= new;
                                  new->next= aux;
                                  ok= 0;
                            }
                            else{
                                  prec->next= new;
                                  new->next= aux;
                                  ok= 0;
                            } 
                    }
                    prec= aux;
                    aux= prec->next;
               }
               if(ok)
                    prec->next= new;
       }
}

void organize(ListaDiElementi l, int k){
       ListaDiElementi aux=NULL, final=NULL;
       while(l!=NULL && k>=0){
               if((k-l->cfu)>=0){
                     insertfinal(&final, l->nome, l->cfu, l->hard);  
                     k-=l->cfu;
               }
               l= l->next;
       }
       aux=final;
       while(aux !=NULL){
               printf("%s\n",aux->nome);
               aux=aux->next;
       }
}




