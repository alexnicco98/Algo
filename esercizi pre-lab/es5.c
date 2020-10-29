#include<stdio.h>
#include<stdlib.h>

typedef struct _nodo{
       int num;
       int *nodo;
}nodo;

typedef struct el{
       int info;
       struct el* next;
}ElementoDiLista;
typedef ElementoDiLista *ListaDiElementi;

int *color=NULL;

int bipartito();

int main(){
       int i,n,x,j;
       scanf("%d",&n);
       nodo *G= malloc(sizeof(nodo)*n);
       color = malloc(sizeof(int)*n);
       for(i=0;i<n;i++){
              scanf("%d",&(G[i].num));
              color[i]= 0;
              G[i].nodo= malloc(sizeof(int)*G[i].num);
              for(j=0;j<G[i].num;j++)
                      scanf("%d",G[i].nodo+j); 
       }
       x=bipartito(G,n);    
       printf("%d\n",x);   

       return 0;
}

int isEmpty(ListaDiElementi q){
       if(q==NULL) return 1;
       else return 0;
}

void enqueue(ListaDiElementi *q, int x){
       ListaDiElementi new= malloc(sizeof(ElementoDiLista));
       new->info=x;
       new->next=NULL;
       if(*q==NULL)
             *q=new;
       else{
             ListaDiElementi aux=*q;
             while(aux->next!=NULL)
                     aux=aux->next;
             aux->next=new;
       }
}

int dequeue(ListaDiElementi *q){
       ListaDiElementi aux=*q;
       int x=aux->info;
       *q=(*q)->next;
       free(aux);
       return x;
}

void bfs_visit(nodo *E, int u){    
       int k,n=0,j=0,x;
       ListaDiElementi q=NULL;
       color[u]=1;
       enqueue(&q,u);
       while(!isEmpty(q)){
              k=dequeue(&q); 
              x=color[k];
              for(int i=0;i<E[k].num;i++){ 
                     j=E[k].nodo[i];
                     if(color[j]==0){ 
                             color[j]=-x;
                             enqueue(&q,j);
                     }      
              } 
       }
}

int bipartito(nodo *G,int n){
       if(G==NULL) return 0;
       int i=0,j;
       bfs_visit(G,i);  
       for(i=0;i<n;i++)
             for(j=0;j<G[i].num;j++)
                     if(color[i]==color[G[i].nodo[j]])
                              return 0;
       return 1;
}


