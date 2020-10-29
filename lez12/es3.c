// Scrivere un programma che legga da tastiera un grafo diretto, 
// una sequenza di m query, ciascuna composta dagli indici di 
// due nodi del grafo e stampi, per ciascuna query, la lunghezza 
// del percorso minimo che collega i rispettivi due  nodi  della 
// query. 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* color=NULL;

typedef struct _nodo{
      int num;
      int *nodo;
}nodo;

struct el{
      int info;
      int dis;
      struct el *next;
};
typedef struct el ElementoDiLista;
typedef ElementoDiLista *ListaDiElementi;

void bfs_visit();

int main(){
       int i,n,j,m,u,v;
       scanf("%d",&n);
       nodo *E =malloc(sizeof(nodo)*n);
       color= malloc(sizeof(int)*n);
       for(i=0;i<n;i++){
               color[i]=0; 
               scanf("%d",&E[i].num);
               E[i].nodo= malloc(sizeof(int)*E[i].num);
               for(j=0;j<E[i].num;j++)
                       scanf("%d",E[i].nodo+j);
                       
       }
       scanf("%d",&m); //numero query
       for(i=0;i<m;i++){  
               scanf("%d",&u);
               scanf("%d",&v);
               bfs_visit(E,u,v);
               for(j=0;j<n;j++)
                      color[j]=0;
       }
       return 0;
}  

void enqueue(ListaDiElementi *q, int v, int m){ //aggiunge in coda
       ListaDiElementi new= malloc(sizeof(ElementoDiLista)),aux=*q;
       new->info=v;
       new->dis=m;
       new->next=NULL;
       if(*q==NULL)
               *q=new;
       else{
               while(aux->next!=NULL)
                      aux=aux->next;
               aux->next=new;
       }
}

int dequeue(ListaDiElementi *q){  //toglie in testa
      if(*q==NULL) return -1;
      int v;
      ListaDiElementi aux=*q; 
      *q=(*q)->next;
      v= aux->info;
      free(aux);
      return v;
}

int isEmpty(ListaDiElementi q){
      if(q==NULL) return 1;
      else return 0;
}

int distanza(ListaDiElementi q){
      return q->dis;
}

void bfs_visit(nodo *E, int u, int v){      // assegna ad ogni nodo del grafo la distanza dalla radice
       if(u==v){                            // tenendo presente la distanza del nodo precedente
              printf("0\n");                // e stampa la distanza quando trova il nodo che si stava cercando
              return;
       }
       int k,n=0,j=0,x=0;
       ListaDiElementi q=NULL;
       color[u]=1;
       enqueue(&q,u,x);
       while(!isEmpty(q)){
              x=distanza(q);
              k=dequeue(&q); 
              if(k==v){
                       printf("%d\n",x);
                       while(!isEmpty(q))
                              dequeue(&q); 
                       return;
              }
              for(int i=0;i<E[k].num;i++){ 
                     j=E[k].nodo[i];
                     if(color[j]==0){ 
                             color[j]=1;
                             enqueue(&q,j,x+1);
                     }      
              } 
       }
       printf("-1\n");
}


