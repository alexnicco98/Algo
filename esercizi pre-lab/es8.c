#include <stdlib.h>
#include <stdio.h>

struct el{
      int info;
      int bocciato;
      struct el *next;
};

typedef struct el ElementoDiLista;
typedef ElementoDiLista *ListaDiElementi;

int hash(int x, int dim){
      int a=3,b=7,p=999149;
      return (((a*x+b)%p)%dim);
}

void Insert();
void incr();
void Delete();

void printlist(ListaDiElementi l){
      if(l!=NULL){
            printf("%d\n",l->info);
            printlist(l->next);
      }
}

int main(){
      int n,x,i,m1,m2,dim,h;
      scanf("%d",&n);
      dim=2*n;
      ListaDiElementi *lis=malloc(sizeof(ListaDiElementi)*dim);
      for(i=0;i<dim;i++)
            lis[i]=NULL;
      for(i=0;i<n;i++){
            scanf("%d",&x);
            h=hash(x,dim);
            Insert(&(lis[h]),x);
      }
      for(i=0;i<dim;i++){
            if(lis[i]!=NULL)
                  printlist(lis[i]);
     }
      scanf("%d",&m1);
      for(i=0;i<m1;i++){
            scanf("%d",&x);
            h=hash(x,dim);
            incr(&(lis[h]),x);
      }
      scanf("%d",&m2);
      for(i=0;i<m2;i++){
            scanf("%d",&x);
            h=hash(x,dim);
            incr(&(lis[h]),x);
      }
      for(i=0;i<dim;i++)
             if(lis[i]!=NULL)
                  Delete(&(lis[i]));
      printf("Dopo la delete\n");
      for(i=0;i<dim;i++){
            if(lis[i]!=NULL)
                  printlist(lis[i]);
     }
      return 0;
}

void Delete(ListaDiElementi *l){
        ListaDiElementi aux=*l;
        while(aux!=NULL && aux->bocciato==2){
              *l=aux->next;
              free(aux);
              aux=*l;
        }
        if(aux!=NULL){
            ListaDiElementi prec=aux;
            aux=prec->next;
            while(aux!=NULL){
                  if(aux->bocciato==2){
                        prec->next=aux->next;
                        free(aux);
                        aux=prec->next;
                  }
                  else{ 
                        prec=aux;
                        aux=prec->next;
                  }
            }
        }
}

void incr(ListaDiElementi *l,int x){
        ListaDiElementi aux=*l;
        while(aux!=NULL && aux->info!=x)
              aux=aux->next;
        if(aux!=NULL)
              aux->bocciato++;
}

void Insert(ListaDiElementi *l,int x){
        ListaDiElementi new=malloc(sizeof(ElementoDiLista));
        new->info=x;
        new->bocciato=0;
        new->next=NULL;
        if(*l==NULL){
              *l=new;
        }
        else{
              ListaDiElementi aux=*l;
              while(aux->next!=NULL && aux->info<x){
                     aux=aux->next;
              }
              if(aux->next==NULL)
                     aux->next=new;
              else{
                     ListaDiElementi prec=aux->next;
                     if(prec->info==x){
                            free(new);
                            return;
                     }                     
                     new->next=aux->next;
                     aux->next=new;
              }
        }
}
