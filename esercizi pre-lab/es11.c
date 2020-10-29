// Sia T un albero. Dati due nodi v,w ∈ T si definisce il Lowest Common 
// Ancestordivew(LCA(v, w)) come l’antenato comune più  profondo.  
// Progettare un algoritmo efficiente per trovare LCA(v, w).
#include <stdio.h>
#include <stdlib.h>

struct _nodo{
    int key;
    int depth;  // profondità
    struct _nodo *left;
    struct _nodo *right;
    struct _nodo *p;   
};
typedef struct _nodo nodo;
typedef nodo *tree;

void insert();
tree Node();
void LCA();

int main(){
    int i,n,x,v,w;
    tree T=NULL;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&x);
        insert(&T,x);
    }
    scanf("%d",&v);
    scanf("%d",&w);
    tree a= Node(T,v);
    tree b= Node(T,w);
    LCA(T,a,b);
    return 0;
}

void LCA(tree t,tree v,tree w){ // Partendo dai nodi v e w risalgo l'albero finchè
    tree a1=v;                  // con incontro un antenato in comune
    tree a2=w;
    while(a1!=a2 && a1!=NULL){
        if(a1->depth>a2->depth)
             a1=a1->p;
        else if(a1->depth==a2->depth){
                   a1=a1->p;
                   a2=a2->p;
             }
             else
                   a2=a2->p;
    }
    printf("%d\n",a1->key);
}

tree Node(tree t,int x){ // restituisce il nodo con chiave x
    if(t==NULL) return t;
    if(t->key==x) return t;
    else  if(x<=t->key) return Node(t->left,x);
          else return Node(t->right,x); 

}

void newnode(tree *t,tree p,int x,int dep){
    (*t)=malloc(sizeof(nodo));
    (*t)->key=x;
    (*t)->left=NULL;
    (*t)->right=NULL;
    (*t)->p=p;
    (*t)->depth=dep;
}

void addpath(tree *t,tree p,int x, int dep){
    if(x<=(*t)->key)
            if((*t)->left!=NULL)
                  addpath(&(*t)->left,(*t)->left,x,dep+1);
            else
                  newnode(&(*t)->left,p,x,dep);
    else
            if((*t)->right!=NULL)
                  addpath(&(*t)->right,(*t)->right,x,dep+1);
            else
                  newnode(&(*t)->right,p,x,dep);
}

void insert(tree *t,int x){
    if(*t==NULL) newnode(t,NULL,x,0);
    else addpath(t,*t,x,1);
}