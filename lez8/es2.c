// Lista bidirezionale
#include <stdio.h>
#include <stdlib.h>

//List structure:
struct elemento {
	int info;
        struct elemento *prec;
	struct elemento *next;
};

typedef struct elemento ElementoDiLista;
typedef ElementoDiLista *ListaDiElementi;

void readList();

void printList(ListaDiElementi tail) {  // Print from the last 
	while(tail!=NULL){      
                printf("%d\n",tail->info);
                tail=tail->prec;
        }               			      
}

int main() {
        int n,x;
        scanf("%d",&n); 
	ListaDiElementi head=NULL, tail=NULL;
        while(n>0){
                n--;
                scanf("%d", &x);
                readList(&head,&tail,x);
        }
	printList(tail);

	return 0;
}

void readList(ListaDiElementi *hd, ListaDiElementi *tl, int x) {
        ListaDiElementi aux= *hd,pre= NULL, item;        	    
	    item = (ListaDiElementi) malloc(sizeof(ElementoDiLista));
            item->info = x;  
            item->next = NULL;
            item->prec=NULL;
	         if(*hd == NULL) {	   // Item is the first element
                      *hd = item; 
                      *tl = item;   
                 }              
                 else {                   // Item is not the first element
                      (*tl)->next= item;  // (sfrutto il fatto che ho la coda della lista,
                      item->prec= *tl;    // e posso inserire immediatamente senza scorrere
                      *tl= item;          // tutta la lista ogni volta)
                 }             
}


