// Dato  un  albero  binario  i  cui  nodi  sono  colorati  di rosso o  
// di nero, progettare un  algoritmo  efficiente  che  calcoli  il  
// numero  di  nodi aventi  lo  stesso  numero di discendenti rossi 
// e neri.  (Nota:  un nodo è discendente di se stesso).
#include <stdio.h>
#include <stdlib.h>

struct _nodo{
      int key;
      int color;    // 0=red, 1=black
      struct _nodo* left;
      struct _nodo* right;
};

typedef struct _nodo nodo;
typedef nodo *tree;

void insert();
int equalsRB();

int main(){
      int i,x,n,col;
      tree T=NULL;
      scanf("%d",&n);
      for(i=0;i<n;i++){
            scanf("%d",&x);
            scanf("%d",&col);
            insert(&T,x,col);
      }
      equalsRB(T);

      return 0;
}

int equalsRB(tree t){
      if(t==NULL) return 0;
      int n;
      int dl= equalsRB(t->left);
      int dr= equalsRB(t->right);
      if(t->color==0)
             n=dl+dr+1;
      else
             n=dl+dr-1;
      if(n==0) printf("%d\n",t->key);
      return n;
}

void newnode(tree *t,int x,int col){
      (*t)=malloc(sizeof(nodo));
      (*t)->key=x;
      (*t)->color=col;
      (*t)->left=NULL;
      (*t)->right=NULL;
}

void addpath(tree *t,int x,int col){
      if(x<=(*t)->key)
              if((*t)->left!=NULL)
                      addpath(&(*t)->left,x,col);
              else
                      newnode(&(*t)->left,x,col);
      else
             if((*t)->right!=NULL)
                      addpath(&(*t)->right,x,col);
              else
                      newnode(&(*t)->right,x,col);
}

void insert(tree *t, int x,int col){
      if(*t==NULL)
              newnode(t,x,col);
      else
              addpath(t,x,col);
}
