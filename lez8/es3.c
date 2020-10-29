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
        printf("(");
	while(lis!=NULL){                 
                printf("%d ", lis->info);
                lis=lis->next;               			
        }
        printf(")\n");
}

int prese(ListaDiElementi lis,int x){
         int ok=0,count=0;
         while(lis!=NULL&&!ok){
                if(lis->info==x)
                      ok=1;                                      
                else{
                      lis=lis->next;
                      count++;
                }
         }
         if(!ok)
            count=-1;
         return count;         
}

void sposta(ListaDiElementi *lis,int x){
           ListaDiElementi cor=*lis,prec=NULL;
           while(cor->info!=x){
                  prec=cor;
                  cor=cor->next;
           }
           if(prec!=NULL){
                  prec->next=cor->next;
                  cor->next=*lis;
                  *lis=cor;
           }
}

int main() {
	ListaDiElementi l;       	
	l= readList();
        int x=l->info,m;
        while(prese(l,x)!=-1){             
              scanf("%d",&x);
              m=prese(l,x);
              if(m!=-1){
                    printf("%d\n",m);
                    sposta(&l,x);   
              }
              else
                    printf("-1\n");      
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


