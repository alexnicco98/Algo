// Scrivere un programma che legga da tastiera un 
// grafo indiretto e stampi 1 se  il  grafo è  
// connesso, 0 altrimenti.  Un grafo `e connesso 
// quando esiste un percorso tra due vertici
// qualunque del grafo.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *color=NULL;
//Node structure:
typedef struct nodo_ {
	int num;
	int *nodo;
} nodo;

void dfs_visit(nodo *G,int i){
       int k,j;
       color[i]=1;
       for(j=0; j<G[i].num; j++){
               k=G[i].nodo[j];
               if(!color[k])
                      dfs_visit(G,k);
       }
}

void connesso(nodo *G, int n){        //faccio la visita DFS a partire da un solo vertice
         int i=rand()%n;              // perchè, se il grafo è connesso visito tutti i vertici
                if(color[i]==0)
                      dfs_visit(G,i);
}

int main() {        
        int n,i,j,ok=1;
        scanf("%d",&n);
        nodo *G=(nodo*)malloc(sizeof(nodo)*n);
        color= malloc(sizeof(int)*n);
        for(i=0;i<n;i++){
                color[i]=0;
                scanf("%d",&(G[i].num));
                G[i].nodo =(int*)malloc(sizeof(int)*G[i].num);
                for(j=0; j<G[i].num; j++){
                        scanf("%d",G[i].nodo+j);     
                }
        }
        connesso(G,n);
        i=0;
        while(i<n && ok){
               if(color[i]!=1)
                       ok=0;
               i++;
        }
        printf("%d\n",ok);                            
                             
	return 0;
}






