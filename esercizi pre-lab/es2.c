#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct el{
      char info[101];
      struct el *next;
};
typedef struct el ElementoDiLista;
typedef ElementoDiLista *ListaDiElementi;

void insert();
void delete();
void printlist();

int compare(const void *a,const void *b){
      char **x=(char**) a,**y=(char**) b;
      return strcmp(*x,*y);
}

int main(){
      int ok=1,x,n=0,i;
      char s[101];
      ListaDiElementi lis=NULL;
      while(ok){
            scanf("%d",&x);
            if(x==1){
                    n++;
                    scanf("%s",s);
                    insert(&lis,s);
            }
            if(x==2){
                    n--;
                    delete(&lis);
             }
             if(x==0)
                    ok=0;                   
      }
      char **a= malloc(sizeof(char *)*n);
      for(i=0;i<n;i++){
             a[i]=malloc(sizeof(char)*101);
             strcpy(a[i],lis->info);
             delete(&lis);
      }
      qsort(a,n,sizeof(char*),compare);
      for(i=0;i<n;i++)
              printf("%s\n",a[i]);
      printf("$\n");
      return 0;
}

void delete(ListaDiElementi *lis){
       if(*lis!=NULL){
               ListaDiElementi aux=*lis;
               *lis=(*lis)->next;
               free(aux);
       }
}

void insert(ListaDiElementi *l, char *s){
       ListaDiElementi new= malloc(sizeof(ElementoDiLista));
       strcpy(new->info, s);
       new->next=NULL;
       if(*l==NULL)
               *l=new;
       else{
               ListaDiElementi aux=*l;
               while(aux->next!=NULL)
                        aux=aux->next;
               aux->next= new;
       }
}
