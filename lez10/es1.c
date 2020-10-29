// Scrivere un programma che legga da tastiera una sequenza di
// n interi distinti e li inserisca in una tabella hash di 
// dimensione 2n posizioni utilizzando liste monodirezionali 
// per risolvere eventuali conflitti. Una  volta  inseriti 
// tutti  gli  interi,  il  programma  deve  stampare  la  
// lunghezza massima delle liste e il numero totale di conflitti.
#include <stdio.h>
#include <stdlib.h>

//Node structure:
struct elemento {
	int info;
	struct elemento *next;
};

typedef struct elemento ElementoDiLista;
typedef  ElementoDiLista *ListaDiElementi;

int len(ListaDiElementi *m,int n){    // calcola la lunghezza massima delle liste
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

int lenght(ListaDiElementi m){   // calcola il numero di conflitti della lista
        if(m==NULL)  return 0;
        else return lenght(m->next)+1;
}

void insert(ListaDiElementi *m,int x){
        if(*m==NULL){
              ListaDiElementi new;
              new=malloc(sizeof(ElementoDiLista));
              new->info=x;
              new->next=NULL;
              *m=new;
        }
        else{
             ListaDiElementi aux=*m;
             while(aux->next!=NULL)
                 aux=aux->next;
             ListaDiElementi new;
             new=malloc(sizeof(ElementoDiLista));
             new->info=x;
             new->next=NULL;
             aux->next=new;
        }
}

int main() {
        int x,n,i=0,a,b,h,p=999149,conta=0;
	scanf("%d",&n);
        scanf("%d",&a);
        scanf("%d",&b);
        ListaDiElementi *m=(ListaDiElementi*)malloc((2*n)*sizeof(ListaDiElementi));
        for(i=0;i<2*n;i++)
              m[i]=NULL;     
        for(i=0;i<n;i++){           
              scanf("%d",&x);
              h=((a*x+b)%p)%(2*n);
              insert(&m[h],x);              
        }
        for(i=0;i<n*2;i++){
              x=lenght(m[i]);
              if(x>0)
                 x--;             
              conta+=x;                  
         }
        printf("%d\n",len(m,2*n));
        printf("%d\n",conta);                              
	return 0;
}
