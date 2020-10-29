// Scrivere una funzione ricorsiva che stampa gli n nodi 
// più piccoli di un albero binario di ricerca (n è un 
// parametro della funzione). 
// Scrivere una funzione ricorsiva che stampa gli n nodi
// più grandi di una lbero binario di ricerca (n é un
// parametro della funzione).
#include <stdio.h>
#include <stdlib.h>

struct _node{
    int key;
    struct _node *left;
    struct _node *right;
};
typedef struct _node nodo;
typedef nodo *tree;

void insert();
void IndexMin();
void IndexMax();

int main(){
    int i,n,x;
    scanf("%d",&n);
    tree T=NULL;
    for(i=0;i<n;i++){
         scanf("%d",&x);
         insert(&T,x);
    }
    scanf("%d",&x);
    printf("%d elementi più piccoli:\n",x);
    IndexMin(T,&x);
    scanf("%d",&x);
    printf("\n");
    printf("%d elementi più grandi:\n",x);
    IndexMax(T,&x);
    return 0;
}

void IndexMin(tree t,int *n){
    if(t==NULL) return;
    IndexMin(t->left,n);
    if(*n>0){
         printf("%d\n",t->key);
         (*n)--;
         IndexMin(t->right,n);
    }   
    return;      
}

void IndexMax(tree t,int *n){
    if(t==NULL) return;
    IndexMax(t->right,n);
    if(*n>0){
        printf("%d\n",t->key);
        (*n)--;
        IndexMax(t->left,n);
    }
}

void newnode(tree *t,int x){
    (*t)=malloc(sizeof(nodo));
    (*t)->key=x;
    (*t)->left=NULL;
    (*t)->right=NULL;
}

void addpath(tree *t,int x){
    if(x<=(*t)->key)
          if((*t)->left!=NULL)
                 addpath(&(*t)->left,x);
          else 
                 newnode(&(*t)->left,x);
    else
          if((*t)->right!=NULL)
                 addpath(&(*t)->right,x);
          else 
                 newnode(&(*t)->right,x);
}

void insert(tree *t,int x){
    if(*t==NULL) newnode(t,x);
    else addpath(t,x);
}
