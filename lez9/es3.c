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

void visit(tree t){  
        if(t!=NULL){       
                visit(t->left);
                printf("%d\n",t->key);  
                visit(t->right);                                        
        }

}

int main() {
        int x,n,i;
        tree T=NULL;
	scanf("%d",&n);
        for(i=0;i<n;i++){           
              scanf("%d",&x);
              insert(&T,x);
        }        
        visit(T);                       
	return 0;
}
