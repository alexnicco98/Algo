#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct puntoColorato{
       int x;  //ascissa
       int y;  //ordinata
       int c; //colore
}typedef pc;

struct interrogazione{
       int x1;
       int y1;
       int x2;
       int y2;
}typedef inter;

int compare(const void* a,const void *b){
    pc *x =(pc*) a,*y =(pc*) b; 
    return (x->c-y->c);  
}

void pcdentro(pc a[],inter b[],int n, int m){
    int i,j,aux=-1,conta=0;
    for(i=0;i<m;i++){
         for(j=0;j<n;j++){
               if(b[i].x1<=a[j].x && a[j].x<=b[i].x2)
                       if(b[i].y1<=a[j].y && a[j].y<=b[i].y2)
                                if(aux!=a[j].c){
                                        aux=a[j].c;
                                        conta++;                                                                   
                                 }                        
         } 
    aux=-1;
    printf("%d\n",conta);
    conta=0;
    } 
       
}             

int main(void){  
      int n,m,i;   
      scanf("%d",&n); 
      scanf("%d",&m); 
      pc a[n];
      inter b[m];  
      for(i=0;i<n;i++){                                 
                  scanf("%d",&a[i].x);
                  scanf("%d",&a[i].y);
                  scanf("%d",&a[i].c);
      }
      for(i=0;i<m;i++){                                 
                  scanf("%d",&b[i].x1);
                  scanf("%d",&b[i].y1);
                  scanf("%d",&b[i].x2);
                  scanf("%d",&b[i].y2);
      }                                        
      qsort(a,n,sizeof(pc),compare);                               
      pcdentro(a,b,n,m);       
      return 0;
      
}
