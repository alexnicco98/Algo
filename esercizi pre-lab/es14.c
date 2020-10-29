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
int SubMin();

int main(){
    int i,x,n;
    scanf("%d",&n);
    tree T=NULL;
    for(i=0;i<n;i++){
         scanf("%d",&x);
         insert(&T,x);
    }
    SubMin(T);
    return 0;
}

int SubMin(tree t){
    if(t==NULL) return 100;
    int sl=SubMin(t->left);
    int sr=SubMin(t->right);
    int min;
    if(t->key<=sl)
         if(t->key<=sr) min=t->key;
         else min=sr;
    else
         if(sl<=sr) min=sl;
         else min=sr;
    printf("chiave %d, min %d\n",t->key,min);
    return min;
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
