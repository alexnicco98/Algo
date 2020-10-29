// Scrivere un programma che riceve in input due sequenze di N
// interi positivi, dalle quali devono essere costruiti due 
// alberi binari di ricerca NON bilanciati (un albero per sequenza).
// Al programma viene data una chiave intera K. Si pu`o assumere
// che l’intero K sia presente in entrambe le sequenze.  
// Il programma deve verificare che le sequenze di chiavi 
// incontrate nel cammino che dalla radice porta al nodo con 
// chiave K nei due alberi coincidano.
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

int search(tree t1,tree t2,int k){  
        if(t1==NULL||t2==NULL)       
               return 0;
        if(t1->key==k && t2->key==k)
               return 1;
        else{
               if(t1->key==t2->key)
                     if(k<t1->key )
                             return search(t1->left,t2->left,k);
                     else
                             return search(t1->right,t2->right,k); 
               else return 0;                                           
        }
}

int main() {
        int x,n,k,i;
        tree T1=NULL,T2=NULL;
	scanf("%d",&n);
        scanf("%d",&k);
        for(i=0;i<n;i++){           
              scanf("%d",&x);
              insert(&T1,x);
        }
        for(i=0;i<n;i++){           
              scanf("%d",&x);
              insert(&T2,x);
        }       
        printf("%d\n",search(T1,T2,k));

	return 0;
}

