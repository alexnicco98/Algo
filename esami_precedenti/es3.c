// Vi verrà data in input la lista di oggetti posseduti
// da Alice e da Bob. Ogni oggetto avrà un nome (una 
// stringa), che ne contraddistingue la tipologia, ed un
// valore affettivo (un intero). Gli oggetti dovranno 
// essere inseriti in una tabella hash a liste di
// trabocco, al fine di scoprire i  duplicati  e  di
// selezionare, a parità di tipologia, l’oggetto col
// valore affettivo maggiore. Ogni oggetto in input dovrà
// essere cercato nella tabellahash.  Vi sono tre casi:
// 1.  la tabella non contiene un oggetto Y per cui 
// nome(X) =nome(Y).In  questo  caso,  bisognerà  
// inserire  l’oggetto X in  cima alla  lista  di
// trabocco;
// 2.  la tabella contiene un oggetto Y per cui
// nome(X) =nome(Y), e per cui valore (X)≤valore(Y).
//  In questo caso non bisogna far nulla; 
// 3.  la  tabella  contiene  un  oggetto Y per  cui
// nome(X) =nome(Y),  e per cui valore (X)>valore(Y).
// In  tal  caso,  bisogner`a  aggiornare Y impostando
// valore(Y) =valore(X).
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ele{
      char nome[101];
      int valore;
      struct ele *next;
};
typedef struct ele ElementoDiLista;
typedef ElementoDiLista *ListaDiElementi;

int hash(char *a,int dim){  // funzione hash sbagliata
      int i=0,som=0;
      while(a[i]){
             som+=a[i];
             i++;
      }
      return som%dim;
}

int compare(const void *a, const void *b){
       ListaDiElementi x=(ListaDiElementi) a,y =(ListaDiElementi) b;
       int c=x->valore,d=y->valore;
       if(c==d) return(strcmp(x->nome,y->nome));
       else return (d-c);
}

void insert();
void printlist();
void ins();
void printlistlist();

int main(){
      int i,n,val,h;
      char *x=malloc(sizeof(char)*101);
      scanf("%d",&n);
      int dim=n*2;
      ListaDiElementi *lis=(ListaDiElementi*)malloc(sizeof(ListaDiElementi)*dim);
      for(i=0;i<dim;i++)
            lis[i]=NULL;
      for(i=0;i<n;i++){
            scanf("%s",x);         
            scanf("%d",&val);
            h=hash(x,dim);
            insert(&lis[h],x,val);
      }
      ListaDiElementi lis1= malloc(sizeof(ElementoDiLista)*n); 
      ListaDiElementi aux=NULL;
      int k=0,d=0;
      for(i=0;i<dim;i++){
            aux=lis[i];
            while(aux!= NULL){
                   strcpy(lis1[k].nome,aux->nome);
                   lis1[k].valore=aux->valore;
                   aux=aux->next;
                        k++;
                } 
      }
      qsort(lis1,k,sizeof(ElementoDiLista),compare);  
      if(k>15) k=15;
      for(i=0;i<k;i++)
             printf("%s\n",lis1[i].nome);              
      return 0;
}

void insert(ListaDiElementi *l,char *x,int val){  // Inserisce in base al caso in cui siamo
          ListaDiElementi aux=*l;
          int ok=1;
          while(aux!=NULL && ok){
                if(strcmp(aux->nome,x)==0){                      
                      if(aux->valore<val)
                             aux->valore=val;
                      ok=0;
                }
                aux=aux->next;          
          }
          if(ok==1){
                ListaDiElementi new=malloc(sizeof(ElementoDiLista));
                strcpy(new->nome,x);
                new->valore= val;
                new->next=NULL;
                if(*l==NULL)
                       *l=new;
                else{
                       new->next=*l;
                       *l=new;
                }
          }         
}




