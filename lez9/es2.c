#include <stdio.h>
#include <stdlib.h>

//Node structure:
struct node {
	int key;
	struct node *left;
        struct node *right;
};

typedef struct node* tree;

void newnode(tree *t,int z){
        (*t)=malloc(sizeof(tree));
        (*t)->key=z;
        (*t)->left=NULL;
        (*t)->right=NULL;     
}

void addpath(tree *t,int z){
        if(z<=(*t)->key)
                if((*t)->left!=NULL)
                        addpath(&(*t)->left,z);
                else
                        newnode(&(*t)->left,z); 
        else
                if((*t)->right!=NULL)
                        addpath(&(*t)->right,z);
                else
                        newnode(&(*t)->right,z);
}

void insert(tree *t,int z){
        if(*t==NULL)
                newnode(t,z);  
        else
                addpath(t,z);
}

int max(int x,int y){
     if(x>=y) return x;
     else return y;
}

int high(tree t){
        int h,hl,hr;
        if(t==NULL) return 0;
        hl=high(t->left);
        hr=high(t->right);
        h=max(hl,hr)+1;
        return h;
}

int main() {
        int x,n,i;
        tree T=NULL;
	scanf("%d",&n);
        for(i=0;i<n;i++){           
              scanf("%d",&x);
              insert(&T,x);
        }        
        printf("%d\n",high(T));                          
	return 0;
}

