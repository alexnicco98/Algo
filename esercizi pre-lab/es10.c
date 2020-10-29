// Distanza in archi tra 2 chiavi x,y con x<y
#include <stdio.h>
#include <stdlib.h>

struct _nodo{
     int key;
     struct _nodo* left;
     struct _nodo* right;
};
typedef struct _nodo nodo;
typedef nodo *tree;

void insert();
int distance();

int main(){
     int i,x,y,n,d;
     tree T=NULL;
     scanf("%d",&n);
     for(i=0;i<n;i++){
            scanf("%d",&x);
            insert(&T,x);
     }
     scanf("%d %d",&x,&y);
     d=distance(T,x,y);
     printf("%d\n",d);
     return 0;
}

int val_as(int x){
     if(x>=0) return x;
     else return -x;
}

int tree_dist(tree t,int z, int d){ // profondità chiave z
     if(t==NULL) return -1;
     if(t->key==z) return d;
     if(z<t->key) return tree_dist(t->left,z,d+1);
     else   return tree_dist(t->right,z,d+1);
}

int distance(tree t,int x ,int y){ // Finchè non ho un antenato in comune scendo 
     if(t==NULL) return -1;        // e diminuisco le profondità
     int d1=0,d2=0;
     int dl= tree_dist(t,x,0);
     int dr= tree_dist(t,y,0);
     if(dl!=-1 && dr!=-1) 
            if(x<=t->key && t->key<=y){
                 return val_as(dl+dr);
                }
            else{
                 while((x<t->key && y<t->key) || (x>t->key && y>t->key)){
                        dl--;
                        dr--;
                        if(y>t->key)                             
                             t=t->right;
                        else
                             t=t->left;
                 }
                 return val_as(dl+dr);
            }
     else return -1;
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
     else   addpath(t,x);
}
