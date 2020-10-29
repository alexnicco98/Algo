// Scrivere un programma che legga da tastiera una sequenza di
// n interi ordinati e li inserisca in una lista bidirezionale.
// Il programma entra poi in un ciclo nel quale legge un intero
// i da tastiera e lo cerca nella lista. Se i si trova nella lista,
// stampa la sua posizione (contando da 0), altrimenti stampa -1.
// Ogni elemento della lista mantiene anche un contatore che ricorda
// quante  volte  `e  stata  cercata  la  corrispondente  chiave.  
// Tutti  i  contatori  sono inizialmente settati a 0.  Dopo ogni 
// ricerca si deve garantire che gli elementi della lista siano
// ordinati in ordine non-crescente di contatore. 
#include <stdio.h>
#include <stdlib.h>

//List structure:
struct elemento {
	int info;
        int cont;
	struct elemento *next;
        struct elemento *prec;
};

typedef struct elemento ElementoDiLista;
typedef ElementoDiLista *ListaDiElementi;

ListaDiElementi readList();

//Function to print all the elements of the list:
void printList(ListaDiElementi lis) {
        printf("(");
	while(lis!=NULL){                 
                printf("%d ", lis->info);
                lis=lis->next;               			
        }
        printf(")\n");
}

void sposta(ListaDiElementi *lis,int x){
           ListaDiElementi cor=*lis,pre=cor->prec,aux;
           while(cor->info!=x){                         // faccio puntare cor all'elemento che 
                  pre=cor;                              // sto cercando e pre a quello precedente
                  cor=cor->next;
           }
           cor->cont=cor->cont+1;                       //aggiorno il contatore
           if(pre!=NULL){
                 while(pre!=NULL && cor->cont>pre->cont){     
                       cor->prec=pre->prec;
                       if(pre->prec!=NULL){
                              aux=pre->prec;
                              aux->next=cor;
                       }
                       pre->next=cor->next;
                       if(cor->next!=NULL){
                              aux=cor->next;
                              aux->prec=pre;
                       }                   
                       pre->prec=cor;
                       cor->next=pre;
                       pre=cor->prec;
                 }
                 if(cor->prec==NULL)                   // se prima di cor non c'è un elemento 
                       *lis=cor;                       // aggiorno la testa perchè è cambiata
           }
}

int prese(ListaDiElementi lis,int x){                 // controllo che x è presente nella lista 
         int ok=0,count=0;                            // e restituisco il suo indice
         ListaDiElementi aux=lis;
         while(aux!=NULL&&!ok){
                if(aux->info==x)
                      ok=1;                                     
                else{
                      aux=aux->next;
                      count++; 
                }
         }
         if(!ok)
            count=-1;
         return count;         
}

int main() {
	ListaDiElementi l;       	
	l= readList();
        int x=l->info,m=0;
        while(m!=-1){             
              scanf("%d",&x);
              m=prese(l,x);
              if(m!=-1)
                    sposta(&l,x);   
              printf("%d\n",m);     
        }

	return 0;
}

//Function to acquire a list of integers:
    ListaDiElementi readList() {
        ListaDiElementi head = NULL;
        ListaDiElementi previous = NULL;
        ListaDiElementi item;
        int n,x;
        scanf("%d", &n); 
	while(n>0) { 
            n--;            
            scanf("%d", &x);            	    
	    item = (ListaDiElementi) malloc(sizeof(ElementoDiLista));
            item->info = x;
            item->cont = 0;  
            item->next = NULL;
            item->prec = NULL;
	         if(previous == NULL) {	//Item is the first element:
                      head = item; 
                      previous=head;   
                 }              
                 else {      //Item is not the first element:
                      previous->next = item;
                      item->prec=previous;
                      previous = item;   
                 }             
	}
        return head;
     }


