#include <stdio.h>
#include <stdlib.h>

struct el{
    int info;
    struct el *next;
};

typedef struct el ElementoDiLista;
typedef ElementoDiLista *ListaDiElementi;


int sommaSuf();
void insert();
void printlist();
int main(){
      int n,i,x,media=0;
      scanf("%d",&n);
      ListaDiElementi lis=NULL;
      for(i=0;i<n;i++){
            scanf("%d",&x);
            insert(&lis,x);
      }
      printlist(lis);
      printf("\n");
      sommaSuf(&lis);
      printlist(lis);
      printf("\n");

}

void delete(ListaDiElementi *l,int x){
      ListaDiElementi aux=*l,prec=NULL;
      while(aux->info!=x){
              prec=aux;
              aux=aux->next;
              }
      prec->next=aux->next;
      free(aux);        
}

int sommaSuf(ListaDiElementi *l){
      if(*l==NULL) return 0;
      ListaDiElementi aux=*l,suc=aux->next;
      if(suc==NULL){
            int a = aux->info;
            aux->info=0;
            return a;
      } 
      else{
            int a = aux->info;
            int b= sommaSuf(&(suc));
            aux->info= b;
            return b+a; 
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



