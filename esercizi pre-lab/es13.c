// Sia T un albero binario, dove ogni nodo v∈T memorizza un valore v.val 
// che può essere 1 o -1. Un nodo v∈T si dice strong se la somma dei valori 
// memorizzati nei nodi del sottoalbero Tv è >0. (Si ricordi che Tv è il 
// sottoalbero con radice v e include v). Progettare un algoritmo ricorsivo 
// per contare il numero di nodi strong in T, analizzandone la complessità.
#include <stdio.h>
#include <stdlib.h>

struct _node{
    int key;
    int val;
    struct _node *left;
    struct _node *right;
};
typedef struct _node nodo;
typedef nodo *tree;

void insert();
int Strong();

int main(){
    int i,n,x,val;
    scanf("%d",&n);
    tree T=NULL;
    for(i=0;i<n;i++){
        scanf("%d",&x);
        scanf("%d",&val);
        insert(&T,x,val);
    }
    int conta =0;
    Strong(T,&conta);
    printf("%d\n",conta);
    return 0;
}
 
int Strong(tree t,int *conta){
    if(t==NULL) return 0;
    int dl=Strong(t->left,conta);
    int dr=Strong(t->right,conta);
    int sum= dl+dr+t->val;
    if(sum>0) (*conta)++;
    return sum;
}

void newnode(tree *t,int x,int val){
    (*t)=malloc(sizeof(nodo));
    (*t)->key=x;
    (*t)->val=val;
    (*t)->left=NULL;
    (*t)->right=NULL;
}

void addpath(tree *t,int x,int val){
    if(x<=(*t)->key)
        if((*t)->left!=NULL)
            addpath(&(*t)->left,x,val);
        else
            newnode(&(*t)->left,x,val);
    else
        if((*t)->right!=NULL)
            addpath(&(*t)->right,x,val);
        else
            newnode(&(*t)->right,x,val);
}

void insert(tree *t,int x,int val){
    if(*t==NULL) newnode(t,x,val);
    else addpath(t,x,val);
}