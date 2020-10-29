#include <stdio.h>
#include <stdlib.h>

struct Node{
     int key;
     struct node *left;
     struct node *right;
};

typedef struct Node* tree;

int max(int a,int b){
       if(a>b) return a;
       return b;
}

void printtree(tree t){
       if(t!=NULL){
             printtree(t->left);
             printf("%d ",t->key);
             printtree(t->right);
       }
}

tree search(tree t,int k){
       if(t==NULL||t->key==k) return t;
       if(k<t->key)
              return search(t->left,k);
       return search(t->right,k);
}

tree searchdad(tree t,int k,tree dad){
       if(t==NULL||t->key==k) return dad;
       dad=t;
       if(k<t->key)
              return searchdad(t->left,k,dad);
       return searchdad(t->right,k,dad);
}

tree treemin(tree t){
      while(t->left!=NULL)
             t=t->left;
      return t;
}

void trasplant(tree *T,tree u,tree v){
      tree a=NULL,b=NULL;
      if(u==*T)
             *T=v;
      else{ 
             a=searchdad(*T,u->key,a);  
             if(u==a->left)
                    a->left=v;
             else
                    a->right=v;
      }
      if(v!=NULL){
             a=NULL;
             a= searchdad(*T,u->key,a);  
             b= searchdad(*T,v->key,b);  
             b=a;
      }
}

void delete(tree *t,tree z){
      tree a,y,b=NULL;
      if(z->left==NULL)
             trasplant(t,z,z->right);
      else   if(z->right==NULL)
                    trasplant(t,z,z->left);
             else{
                    y=treemin(z->right);
                    a= searchdad(*t,y->key,b);  
                    b=NULL;
                    if(a!=z){
                           trasplant(t,y,y->right);
                           y->right=z->right;
                           a=y->right;
                           a= searchdad(*t,a->key,b);  
                           b=NULL;
                           a=y;
                    }
                    trasplant(t,z,y);
                    y->left=z->left;
                    a=y->left;
                    a= searchdad(*t,a->key,b);  
                    a=y;   
             }
      
}

int high(tree t){
      int hl,hr,h;
      if(t==NULL) return 0;
      hl=high(t->left);
      hr=high(t->right);
      h=max(hl,hr)+1;
      return h;
}

void insert(tree *T,tree z){
      tree y=NULL;
      tree x=*T;
      while(x!=NULL){
            y=x;
            if(z->key<x->key)
                   x=x->left;
            else 
                   x=x->right;                   
      }
      if(y==NULL)
             *T=z;
      else   if(z->key<y->key)
                      y->left=z;
             else
                      y->right=z;
}

int main(){ 
     int i,x,n;
     tree T=NULL,t=NULL,dad=NULL;
     scanf("%d",&n);
     for(i=0;i<n;i++){
           scanf("%d",&x);
           t=malloc(sizeof(tree));
           t->key= x;
           t->left= NULL;
           t->right= NULL;
           insert(&T,t);
     }
     printf("%d\n",high(T));
     printtree(T);
     printf("\n");
     x=1000;
     while(x>=0){
           scanf("%d",&x);
           if(x>=0){
                  t= search(T,x);                  
                  delete(&T,t);
                  printtree(T);
                  printf("\n");
           }
     }
}












