// Dato un albero binario, definiamo “ visita sinistra ” 
// dell’albero la visita che, partendo dalla radice, opera 
// ricorsivamente come segue:  se un nodo ha un figlio 
// sinistro s,  tale  figlio  `e  visitato  e  la  visita
//  prosegue  da s;  altrimenti termina. In modo speculare 
// ma a destra definiamo "visita destra". Per ogni nodo
// u, consideriamo il sottoalbero radicato in u. Si definiscono:
// •L(u):  il numero di nodi visitati dalla “visita sinistra”
// del sottoalbero, escluso u
// •R(u):  il numero di nodi visitati dalla “visita destra”
// del sottoalbero, escluso u
//  Il  programma deve poi stampare in ordine crescente le
// chiavi dei nodi che soddisfano la condizione L(u)> R(u).
#include <stdio.h>
#include <stdlib.h>

struct node{
      int key;
      struct node *left;
      struct node *right;
};

typedef struct node Nodo;
typedef Nodo *tree;

void insert();
int leftVisit();
int rightVisit();
void CondTrue();

int main(){
      int i,n,x;
      tree T=NULL;
      scanf("%d",&n);
      for(i=0;i<n;i++){
            scanf("%d",&x);
            insert(&T,x);
      }
      CondTrue(T);
      return 0;
}

void CondTrue(tree t){
      if(t==NULL) return;
      else{
            CondTrue(t->left);
            if(leftVisit(t)>rightVisit(t))
                    printf("%d\n",t->key);
            CondTrue(t->right);
      }
}

int leftVisit(tree t){
      if(t==NULL) return -1;
      else
         return leftVisit(t->left)+1;
}

int rightVisit(tree t){
      if(t==NULL) return -1;
      else
         return rightVisit(t->right)+1;
}

void insert(tree *t,int x){
      tree new=malloc(sizeof(Nodo));
      new->key=x;
      new->left= NULL;
      new->right= NULL;
      if(*t==NULL) *t=new;
      else{
           tree aux=*t,prec;
           while(aux!=NULL){
                 prec=aux;
                 if(x<=aux->key)
                      aux=aux->left;
                 else  aux=aux->right;
           }
           if(x<=prec->key)
                 prec->left=new;
           else  prec->right=new;
           
      }
}

