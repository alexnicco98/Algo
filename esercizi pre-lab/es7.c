#include <stdio.h>
#include <stdlib.h>

//Node structure:
struct node {
	int key;
	struct node *left;
        struct node *right;
};

typedef struct node nodo;
typedef nodo *tree;

void newnode(tree *t,int z){
        (*t)=malloc(sizeof(nodo));
        (*t)->key=z;
        (*t)->left=NULL;
        (*t)->right=NULL;     
}

void addpath(tree *t,int z){
        if(z<(*t)->key){
                if((*t)->left!=NULL)
                        addpath(&(*t)->left,z);
                else
                        newnode(&(*t)->left,z); 
        }
        else{
                if((*t)->right!=NULL)
                        addpath(&(*t)->right,z);
                else
                        newnode(&(*t)->right,z);
        }
}

void insert(tree *t,int z){
        if(*t==NULL)
               newnode(t,z); 
        else
                addpath(t,z);
}

int visit(tree t,int som){
         if(t!=NULL){
                som+= t->key;
                int a=visit(t->left,som);
                int b=visit(t->right,som);
                int z= a+b+t->key;
                if(z==som)
                      printf("%d\n",t->key);
                return z;
         }
         else return 0;
}

int main() {
        int x,n,i;
        tree T=NULL;
	scanf("%d",&n);
        for(i=0;i<n;i++){           
              scanf("%d",&x);
              insert(&T,x);
        }     
        x=0;   
        visit(T,x);                       
	return 0;
}
