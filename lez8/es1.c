#include <stdio.h>
#include <stdlib.h>

//List structure:
struct elemento {
	int info;
	struct elemento *next;
};

typedef struct elemento ElementoDiLista;
typedef ElementoDiLista *ListaDiElementi;

ListaDiElementi readList();

//Function to print all the elements of the list:
void printList(ListaDiElementi lis) {
	if(lis==NULL)
                return;
        else{           
                printList(lis->next); 
                printf("%d\n", lis->info);               			
        }
}

int main() {
	ListaDiElementi l;

	//Read and print the list:
	l= readList();
	printList(l);

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
            item->next = NULL;
	         if(previous == NULL) {	//Item is the first element:
                      head = item; 
                      previous=head;   
                 }              
                 else {      //Item is not the first element:
                      previous->next = item;
                      previous = item;
                 }             
	}
        return head;
     }


