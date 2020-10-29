// ES1
#include <stdio.h>
#include <stdlib.h>

int graph_size=0;
int *colors=NULL;

typedef struct el{
      int num;
      int *nodo;
}nodo;

nodo* readgraph();
void rec_dfs();
int biparted();

int main(){
     int i;
     nodo *E=NULL;
     E=readgraph();
     colors=malloc(sizeof(int)*graph_size);
     for(i=0;i<graph_size;i++)
            colors[i]=0;
     printf("%d\n",biparted(E,0,1));
     return 0;
}

void rec_dfs(nodo *E,int src, int col){
      int dest,i;
      for(i=0;i<E[src].num;i++){
             dest=E[src].nodo[i];
             if(!colors[dest]){
                  colors[dest]=col;
                   rec_dfs(E,dest,-col);
             }
      }
}

int biparted(nodo *E, int v, int col){
      rec_dfs(E,v,1);
      for(int i=0;i<graph_size;i++)
             for(int j=0;j<E[i].num;j++)
                    if(colors[i]==colors[E[i].nodo[j]])
                          return 0;
      return 1;
}

nodo* readgraph(){
      nodo *E=NULL;
      int i,j,n;
      scanf("%d",&n);
      graph_size=n;
      E=(nodo*)malloc(sizeof(nodo)*n);
      for(i=0;i<n;i++){
             scanf("%d",&E[i].num);
             E[i].nodo=(int*)malloc(sizeof(int)*E[i].num);
             for(j=0;j<E[i].num;j++)
                      scanf("%d",E[i].nodo+j);
                      
      }
      return E;
}
