// Dato un albero binario di ricerca, definiamo la somma 
// di un cammino come la  somma  delle  chiavi  dei  nodi 
// appartenenti  al  cammino. Consideriamo  i cammini di 
// somma massima (si noti come, in generale, possono 
// esistere più cammini di somma massima).  Il programma 
// deve stampare la chiave pi`u piccola appartenente ad un 
// cammino di somma massima.
#include <stdio.h>
#include <stdlib.h>

struct node{
      int key;
      int prop;
      struct node *left;
      struct node *right;      
};
typedef struct node nodo;
typedef nodo *tree;

void insert();      //inserisco un nodo nell'albero 
void printTree();
int camminoMax();

int main(){
      tree T=NULL;
      int i,n,x,min;
      scanf("%d",&n);
      
      for(i=0;i<n;i++){
             scanf("%d",&x);
             insert(&T,x);
      }
      min=0;
      x=camminoMax(T,&min);
      printf("%d\n",min);
}

int camminoMax(tree t,int *min){             // visita tutto l'albero e salva la chiave più piccola
      int a,b,c;                             // appartenente al cammino massimo ( se la chiave si trova a
      if(t==NULL) return 0;                  // a sinistra, prende quella più a sinistra mentre se si trova 
      a=camminoMax(t->left,min)+ t->key;     // a destra l'aggiorna via via che risale)
      b=camminoMax(t->right,min)+ t->key;
      if(b>a){
             c= b+t->key;
             *min=t->key;
      }else{
             c=a+t->key;
             if(*min==0) *min=t->key;
       }
      return c;   
}

void insert(tree *t,int x){
      tree new=malloc(sizeof(nodo));
      new->key=x;
      new->prop=0;
      new->left=NULL;
      new->right=NULL;
      if(*t==NULL)
             *t=new;
      else{
             tree aux=*t,suc;
             while(aux!=NULL){
                    suc=aux;
                    if(x<=aux->key)
                           aux=aux->left;
                    else aux= aux->right;
             }
             if(x<=suc->key)
                    suc->left= new;
             else   suc->right= new;
      }
}

void printTree(tree t){
       if(t==NULL) return;
       else{
             printTree(t->left);
             printf("%d\n",t->key);
             printTree(t->right);
       }
}
