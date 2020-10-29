// Scrivere un programma che legga da tastiera un grafo 
// indiretto e stampi 1 se  il  grafo `e  bipartito, 0
// altrimenti. Il  grafo `e  rappresentato  nel  seguente
// formato:  la prima riga contiene il numero n di nodi,
// le successive n righe contengono, per ciascun nodo i,
// con 0≤i<n , il numero ni di archi uscenti da i
// seguito da una lista di ni nodi destinazione.
// Un grafo bipartito `e un grafo tale che l’insieme dei 
// suoi vertici si può partizionare in due sottoinsiemi 
// in cui ogni vertice `e collegato solo a vertici
// appartenenti alla partizione opposta.
#include <stdio.h>
#include <stdlib.h>

int graph_size=0;
int *colors=NULL;

typedef struct _nodo {
	int num;
	int *nodo;
} nodo;

//Lettura grafo
nodo *read_graph(){
       nodo *E;
       int n,i,j;
       scanf("%d",&n);
       graph_size=n;
       E=(nodo*)malloc(sizeof(nodo)*n);
       for(i=0;i<n;i++){
              scanf("%d",&(E[i].num));
              E[i].nodo=(int*)malloc(sizeof(int)*E[i].num);
              for(j=0;j<E[i].num;j++)
                       scanf("%d",E[i].nodo+j);
       }
       return E;
}

// Visita DFS , "colora" i nodi con 2 colori differenti
void rec_dfs(int src,nodo *E,int found){
        int dest;
        if(colors[src]==0)
                colors[src]=found;
        for(int i=0;i<E[src].num;i++){
                dest=E[src].nodo[i];
                if(!colors[dest])
                       rec_dfs(dest,E,-found);
        }
}

// Verifico se il grafo è bipartito (se i nodi adiacenti 
// al vertice hanno un colore diverso)
int biparted(nodo *E,int v,int found){
        rec_dfs(v,E,1);
        for(int i=0;i<graph_size;i++)
              for(int j=0;j<E[i].num;j++)     
                     if(colors[i]==colors[E[i].nodo[j]])
                            return 0;
        return 1;
}

int main() {        
        nodo *E=NULL;
        colors=malloc(graph_size*sizeof(int));
        E=read_graph();
        for(int i=0;i<graph_size;i++)
                colors[i]=0;
        printf("%d\n",biparted(E,0,1)); 
                                                                                   
	return 0;
}

