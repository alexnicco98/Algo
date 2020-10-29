#include<stdio.h>
#include<stdlib.h>

typedef struct _nodo{
       int key;
       struct _nodo *left;
       struct _nodo *right;
}nodo;

typedef nodo *tree;

void insert();
int camMax();

void printTree(tree t){
      if(t!=NULL){
               printTree(t->left);
               printf("%d\n",t->key);
               printTree(t->right);
      }
}

int main(){
       int n,x,i;
       tree E=NULL;
       scanf("%d",&n);
       for(i=0;i<n;i++){
               scanf("%d",&x);
               insert(&E,x);
       }
       x=100;
       camMax(E,&x); 
       if(x==100) 
               printf("%d\n",0);  
       else 
               printf("%d\n",x);  

       return 0;
}

int max(int a,int b){
       if(a>=b) return a;
       else return b;
}

int camMax(tree t,int *min){
       int a,b,c;
       if(t==NULL) return 0;
       a=camMax(t->left,min)+t->key;
       b=camMax(t->right,min)+t->key;
       if(a>=b){
               if(*min==100)
                       *min=t->key;
       }
       else{
               *min=t->key;
       }
       //printf("%d\n",*min); 
       return max(a,b);
}

void newnode(tree *t,int x){
       *t=malloc(sizeof(nodo));
       (*t)->key=x;
       (*t)->left=NULL;
       (*t)->right=NULL;
}

void addpath(tree *t,int x){
       if(*t==NULL)
               newnode(t,x);
       else
               if(x<=(*t)->key)
                       addpath(&(*t)->left,x);
               else
                       addpath(&(*t)->right,x);
               
}

void insert(tree *t,int x){
       if(*t==NULL)
               newnode(t,x);
       else
               addpath(t,x);
}



