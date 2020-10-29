// Dato un albero binario di ricerca con i nodi colorati di rosso (0) 
// o di nero (1) stabilire la dimensione del sottoalbero rosso più 
// grande.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Node structure:
struct node {
	int key;
        int dim;    // dimensione sottoalbero rosso
        int color;  // rosso=0, nero=1
        bool sub;   // sottoalbero è rosso
	struct node *left;
        struct node *right;
};

typedef struct node nodo;
typedef nodo *tree;

void newnode(tree *t,int z,int col){
        (*t)=malloc(sizeof(nodo));
        (*t)->key=z;
        (*t)->color=col;
        (*t)->left=NULL;
        (*t)->right=NULL;     
}

void addpath(tree *t,int z,int col){
        if(z<(*t)->key){
                if((*t)->left!=NULL)
                        addpath(&(*t)->left,z,col);
                else
                        newnode(&(*t)->left,z,col); 
        }
        else{
                if((*t)->right!=NULL)
                        addpath(&(*t)->right,z,col);
                else
                        newnode(&(*t)->right,z,col);
        }
}

void insert(tree *t,int z,int col){
        if(*t==NULL)
               newnode(t,z,col); 
        else
                addpath(t,z,col);
}

void subtree(tree x,int *max){
        if(x==NULL) return;
        subtree(x->left,max);  
        subtree(x->right,max);
        x->sub= (x->color==0);
        x->dim=0;
        if(x->sub){
               tree al=x->left, ad=x->right;
               if(al!=NULL && ad!=NULL){         
                      x->sub=(al->sub && ad->sub);
                      if(x->sub)
                            x->dim=1+al->dim+ad->dim;
               }
               else if(al!=NULL){
                           x->sub=(al->sub);
                           if(x->sub)
                                 x->dim=1+al->dim;
                    }
                    else  if(ad!=NULL){
                                 x->sub=(ad->sub);
                                 if(x->sub)
                                      x->dim=1+ad->dim;
                          } 
                          else x->dim=1;
              if(x->dim>*max) *max=x->dim;        
        }
}

int main() {
        int x,n,i,col;
        tree T=NULL;
	scanf("%d",&n);
        for(i=0;i<n;i++){           
              scanf("%d",&x);
              scanf("%d",&col);
              insert(&T,x,col);
        }        
        int max=0;
        subtree(T,&max); 
        printf("%d\n",max);                       
	return 0;
}
