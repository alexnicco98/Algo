// Si definisca la heightsum di un albero binario T come la somma 
// delle altezze di tutti i suoi nodi. (Si ricordi che l’altezza
// di una foglia é 0, e quella di un nodo interno è 1+la massima 
// altezza dei suoi figli.)
#include <stdio.h>
#include <stdlib.h>

struct _nodo{
    int key;
    struct _nodo *left;
    struct _nodo *right;
};
typedef struct _nodo nodo;
typedef nodo *tree;

void insert();
int HeightSum();

int main (){
    int i,n,x;
    tree T=NULL;
    scanf("%d",&n);
    for(i=0;i<n;i++){
         scanf("%d",&x);
         insert(&T,x);
    }
    int sum=HeightSum(T);
    printf("%d\n",sum);
    return 0;
}

int max(int x, int y){
    if(x>=y) return x;
    else return y;
}

int HeightSum(tree t){
    if(t==NULL) return -1;
    int hs= HeightSum(t->left);
    int hd= HeightSum(t->right);
    int h= max(hs,hd)+1;
    if(hs!=-1 && hd!=-1)
        return hs+hd+h;
    else if(hs!=-1)
            return hs+h;
         else if(hd!=-1)
                  return hd+h;
               else return h;
}

void newnode(tree *t,int x){
    (*t)=malloc(sizeof(nodo));
    (*t)->key=x;
    (*t)->left=NULL;
    (*t)->right=NULL;
}

void addpath(tree *t, int x){
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