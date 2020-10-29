// Scrivere un programma che riceva in input una sequenza di
// N interi positivi e costruisca un albero ternario di ricerca
// non bilanciato.  L’ordine di inserimento dei valori nell’albero
// deve coincidere con quello della sequenza. Ogni  nodo  in  un 
// albero  ternario  di  ricerca  pu`o  avere  fino  a  tre  figli:
// figlio sinistro, figlio centrale e figlio destro.  L’inserimento
// di un nuovo valore avviene partendo dalla radice dell’albero e 
// utilizzando la seguente regola. Il valore da inserire viene 
// confrontato con la chiave del nodo corrente.  Ci sono tre 
// possibili casi in base al risultato del confronto:
// 1. se il valore `e minore della chiave del nodo corrente, 
// esso viene inserito ricorsivamente nel sottoalbero radicato 
// nel figlio sinistro;
// 2.  se  il  valore  `e divisibile per  la  chiave  del  nodo 
// corrente,  esso  viene inserito ricorsivamente nel sottoalbero
// radicato nel figlio centrale;
// 3.  in ogni altro caso il valore viene inserito ricorsivamente
// nel sottoalbero radicato nel figlio destro.
// Il programma deve stampare il numero di nodi dell’albero che
// hanno tre figli.
#include <stdio.h>
#include <stdlib.h>

//Node structure:
struct node {
	int key;
	struct node *left;
        struct node *central;
        struct node *right;
};

typedef struct node nodo;
typedef  nodo *tree;

void newnode(tree *t,int z){
        (*t)=malloc(sizeof(nodo));
        (*t)->key=z;
        (*t)->left=NULL;
        (*t)->central=NULL;
        (*t)->right=NULL;     
}

void addpath(tree *t,int z){
        if(z<(*t)->key)
              if((*t)->left!=NULL)
                      addpath(&((*t)->left),z);
              else
                      newnode(&((*t)->left),z); 
        else
              if(z%(*t)->key==0)  
                      if((*t)->central!=NULL)
                              addpath(&((*t)->central),z);
                      else
                              newnode(&((*t)->central),z);
              else
                      if((*t)->right!=NULL)
                              addpath(&((*t)->right),z);
                      else
                              newnode(&((*t)->right),z); 
}

void insert(tree *t,int z){
        if(*t==NULL)
                newnode(&(*t),z);  
        else
                addpath(&(*t),z);
}



int visit(tree t){  //n aumenta se un nodo ha tre figli
        if(t==NULL)
             return 0;       
       if(t->left!=NULL&&t->central!=NULL&&t->right!=NULL) 
                   return (visit(t->left)+visit(t->central)+visit(t->right)+1); 
              else
                   return (visit(t->left)+visit(t->central)+visit(t->right));
                                             
}

int main() {
        int x,n,i;
        tree T=NULL;
	scanf("%d",&n);
        for(i=0;i<n;i++){           
              scanf("%d",&x);
              insert(&T,x);
        }        
        printf("%d\n",visit(T));                      
	return 0;
}
