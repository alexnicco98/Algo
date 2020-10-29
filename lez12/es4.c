// Scrivere  un  programma  che  legga  da  tastiera  un  
// grafo  diretto  e  stampi  il diametro del grafo. 
// Il diametro di un grafo `e la lunghezza del “più lungo
// cammino minimo” fra tutte le coppie di nodi.  
// Il programma deve eseguire una visita BFS a partire 
// da ciascun nodo i del grafo per stabilire il cammino
// minimo più lungo a partire da i , e quindi stampare 
// il massimo tra tutti questi.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _nodo{
       int num;
       int *nodo;
}nodo;

struct el{
       int info;
       int dist;
       struct el *next;
};
typedef struct el ElementoDiLista;
typedef ElementoDiLista *ListaDiElementi;

int *color=NULL;

int bfs_visit(); 
int dequeue();
void enqueue();
int isEmpty();
int distanza();

int main(){
       int i,j,n,x,max,in=0;
       scanf("%d",&n);
       nodo *E= malloc(sizeof(nodo)*n);
       color= malloc(sizeof(int)*n);
       for(i=0;i<n;i++){
              color[i]=0;
              scanf("%d",&E[i].num);
              E[i].nodo= malloc(sizeof(int)*E[i].num);
              for(j=0;j<E[i].num;j++)
                      scanf("%d",E[i].nodo+j);
       }       
       max=0;
       for(i=0;i<n;i++){
            in=0;
            for(j=0;j<n;j++){
                      x=bfs_visit(E,i,j);
                      for(int l=0;l<n;l++)
                               color[l]=0;
                      if(x==-1){
                             printf("-1\n");
                             return 0;
                      }
                      if(x>max) max=x;
            }
       }
       printf("%d\n",max);
       return 0;
}

int isEmpty(ListaDiElementi q){
        if(q==NULL) return 1;
        else return 0;
}

int distanza(ListaDiElementi q){
       return q->dist;
}

int bfs_visit(nodo *E, int u, int v){
       if(u==v) return 0;
       int n=0,i,j,k;
       color[u]=1;
       ListaDiElementi q=NULL;
       enqueue(&q,u,n);
       while(!isEmpty(q)){
               n=distanza(q);
               k=dequeue(&q);
               if(k==v){
                       while(!isEmpty(q))
                               dequeue(&q);
                       return n;
               }
               for(i=0;i<E[k].num;i++){
                       j=E[k].nodo[i];
                       if(color[j]==0){
                              color[j]=1;
                              enqueue(&q,j,n+1);
                       }
               }
       } 
       return -1;   
}

void enqueue(ListaDiElementi *q, int v, int n){ // aggiunge in coda
       ListaDiElementi new,aux=*q;
       new= malloc(sizeof(ElementoDiLista));
       new->info=v;
       new->dist=n;
       new->next=NULL;
       if(*q==NULL)
               *q=new;
       else{
               while(aux->next!=NULL)
                       aux=aux->next;
               aux->next= new;
       }     
}

int dequeue(ListaDiElementi *q){               // toglie in testa
       ListaDiElementi aux=*q;
       if(*q==NULL) return -1;
       *q=(*q)->next;
       int v=aux->info;
       free(aux);
       return v;
}

