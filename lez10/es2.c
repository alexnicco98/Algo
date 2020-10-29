#include <stdio.h>
#include <stdlib.h>


//Node structure:
struct elemento {
	int info;
	struct elemento *next;
};

typedef struct elemento ElementoDiLista;
typedef  ElementoDiLista *ListaDiElementi;

int len(ListaDiElementi *m,int n){
        int i,max=0,conta=0;       
        for(i=0;i<n;i++){
              ListaDiElementi aux=m[i];
              while(aux!=NULL){
                    conta++;
                    aux=aux->next;                   
              }
              if(conta>max)
                    max=conta;
              conta=0;
        }
        return max;
}

int lenght(ListaDiElementi m){
        if(m==NULL)  return 0;
        else return lenght(m->next)+1;
}

void insert(ListaDiElementi *m,int x){ //se l'elemento è presente nella lista non fa niente
        if(*m==NULL){                  //altrimenti, lo inserisce
              ListaDiElementi new;
              new=malloc(sizeof(ElementoDiLista));
              new->info=x;
              new->next=NULL;
              *m=new;
        }
        else{
             ListaDiElementi aux=*m;
             if(aux->info!=x){                  
                   while(aux->next!=NULL){
                         if(aux->info==x) return;
                         aux=aux->next;
                   }
                   ListaDiElementi new;
                   new=malloc(sizeof(ElementoDiLista));
                   new->info=x;
                   new->next=NULL;
                   aux->next=new;
             }
        }
}

int main() {
        int x,n,i=0,a,b,h,p=999149,conf=0,different=0;
	scanf("%d",&n);
        scanf("%d",&a); 
        scanf("%d",&b);
        ListaDiElementi*m=malloc((2*n)*sizeof(ListaDiElementi));
        for(i=0;i<2*n;i++)
              m[i]=NULL;     
        for(i=0;i<n;i++){  //inserisco gli elementi nella lista         
              scanf("%d",&x);
              h=((a*x+b)%p)%(2*n);
              insert(&m[h],x);              
        }
        for(i=0;i<n*2;i++){
              ListaDiElementi aux=m[i];
              x=lenght(m[i]);
              different+=x;
              if(x>0)
                 x--;             
              conf+=x;                  
         }        
        printf("%d\n",conf);  
        printf("%d\n",len(m,2*n));
        printf("%d\n",different);                             
	return 0;
}
