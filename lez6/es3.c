// Qsort e struct
#include <stdio.h>
#include <stdlib.h>

struct point{
       int x;
       int y;
}typedef Point;

int compare(const void* a,const void* b){ // ordina ipunti del piano per ascissa crescente,
       Point *c=(Point*) a;               // a parità di ascissa per ordinata descrescente
       Point *d=(Point*) b; 
       if(c->x==d->x)              
              return (d->y-c->y); 
       else
              return (c->x-d->x); 
  
}              

int main(void){   
      int n,i,j,x;   
      scanf("%d",&n); 
      Point a[n];  
      for(i=0;i<n;i++){                  
                  scanf("%d",&a[i].x);
                  scanf("%d",&a[i].y);
      }
                                         
      qsort(a,n,sizeof(Point),compare);
      for(i=0;i<n;i++)                
            printf("%d %d\n",a[i].x,a[i].y);   
            
      return 0;
      
}
