#include<stdio.h>
#include<stdlib.h>

struct _nodo{
       int num;
       int *nodo;
};
typedef struct _nodo nodo;

nodo *comp();
void printnode();

int main(){
       int x,n,i;
       scanf("%d",&n);
       nodo *G= malloc(sizeof(nodo)*n);
       for(i=0;i<n;i++){
              scanf("%d",&G[i].num);
              G[i].nodo =malloc(sizeof(int)*G[i].num);
              for(int j=0;j<G[i].num;j++)
                      scanf("%d",G[i].nodo+j);
       }
       //printnode(G,n);
       nodo *E=comp(G,n);
       printnode(E,n);

       return 0;
} 

nodo* comp(nodo *G,int n){
       if(G==NULL) return NULL;
       int x,k=0,in=0,j=0;
       nodo *E= malloc(sizeof(nodo)*n);
       for(int i=0;i<n;i++){
              x=n-G[i].num-1; 
              E[i].num=x;
              E[i].nodo= malloc(sizeof(int)*E[i].num);
              while(j<E[i].num){
                         E[i].nodo[j]=in;
                         if(E[i].nodo[j]==i)
                               j--;
                         if(k<G[i].num){
                              if(E[i].nodo[j]==G[i].nodo[k]){
                                      j--;
                                      k++;
                               }
                         }
                         in++;
                         j++;
               }       
               in=0;
               k=0;
               j=0;              
        }
        return E;
}

void printnode(nodo *E,int n){
       for(int i=0;i<n;i++){
              int x=E[i].num;
              printf("%d ",x);
              for(int j=0;j<E[i].num;j++){
                      //x= (int)E[i].nodo[j];
                      printf("%d ",E[i].nodo[j]);
              }
              printf("\n");
       }
}




