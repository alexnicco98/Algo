#include<stdio.h>
#include<stdlib.h>

struct el{
     int info;
     struct el *next;
};
typedef struct el ElementoDiLista;
typedef ElementoDiLista *ListaDiElementi;

int hash(int x, int a, int b, int p, int dim){
      return ((a*x+b)%p)%dim;
}

int insert();
void esamina();

int main(){
     int n,x,p=999149,dim,a,b,i,h,distinti=0;
     scanf("%d",&n);
     dim=2*n;
     scanf("%d",&a);
     scanf("%d",&b);
     ListaDiElementi *lis= malloc(sizeof(ListaDiElementi)*dim);
     for(i=0;i<dim;i++)
            lis[i]=NULL;
     for(i=0;i<n;i++){
            scanf("%d",&x);
            h=hash(x,a,b,p,dim);
            x=insert(&lis[h],x);
            if(x==1) distinti++;
     }
     int conflitti=0, max=0;
     for(i=0;i<dim;i++)
            esamina(lis[i],&conflitti,&max,0);
     printf("%d\n",conflitti);
     printf("%d\n",max);
     printf("%d\n",distinti);
     return 0;
}

void esamina(ListaDiElementi l,int *conf,int *max,int n){
      if(l==NULL) return;
      if(l->next==NULL)
             n=1; 
      else{ 
             while(l->next!=NULL){
                   n++; 
                   (*conf)++; 
                   l=l->next; 
             }
             n++; 
      }
      if(n>*max) *max=n;
}

int insert(ListaDiElementi *l, int x){
     if(*l==NULL){
             ListaDiElementi new= malloc(sizeof(ElementoDiLista));
             new->info=x;
             new->next=NULL;
             *l=new;
             return 1;
     }
     else{
             ListaDiElementi aux=*l;
             while(aux->next!=NULL){
                   if(aux->info==x)
                          return 0;
                   else
                          aux=aux->next;
             }
             if(aux->info==x)
                   return 0;
             ListaDiElementi new= malloc(sizeof(ElementoDiLista));
             new->info=x;
             new->next=NULL;
             aux->next=new;
             return 1;
     }
}




