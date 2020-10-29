// Scrivere un programma che legga da tastiera una sequenza di
// N interi distinti e li inserisca in un albero binario di ricerca 
// (senza ribilanciamento). Il programma entra poi  in un ciclo 
// infinito nel quale legge  un intero i da tastiera  e  lo  cerca 
//  nell’albero. Il  ciclo  termina  solo  se  l’intero i inserito `e
// strettamente minore di 0. Se i si trova nell’albero stampa la 
// profondità alla quale l’elemento si trova (contando da 0), 
// altrimenti stampa NO.
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

int search(tree t,int k,int p){  //p=profondità alla quale si trova il nodo
        if(t==NULL)       
               return -1;
        if(t->key==k)
               return p;
        else{
               if(k<t->key)
                     return search(t->left,k,p+1);
               else
                     return search(t->right,k,p+1);                                            
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
        while(x>=0){
              scanf("%d",&x);
              if(x>=0){
                    i=search(T,x,0);
                    if(i==-1)
                           printf("NO\n");  
                    else  
                           printf("%d\n",i);    
              }
        }
	return 0;
}

