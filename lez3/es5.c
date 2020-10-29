#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int distribuzione(int a[], int sx, int px, int dx) { 
    int x=a[px],i=sx-1,aux;
    aux=a[dx];
    a[dx]=a[px];
    a[px]=aux;
    for(int j=sx;sx<dx;j++)
        if(a[j]<=x){
             i++;
             aux=a[i];
             a[i]=a[j];
             a[j]=aux;
        }
    i++;
    aux=a[i];
    a[i]=x;
    a[px]=aux;
    return i;  
}

void quicksort( int a[], int sx, int dx ) {
  
  int perno, pivot;
  if( sx < dx ) {
    pivot = (rand()%(dx-sx+1))+sx;
    perno = distribuzione(a, sx, pivot, dx); /* separa gli elementi minori di a[pivot] 
					        da quelli maggiori o uguali */
    /* Ordina ricorsivamente le due metà */
    quicksort(a, sx, perno-1);
    quicksort(a, perno+1, dx);   
  }

}

/* Lettura di un array di interi da input. 
Il primo elemento è la lunghezza dell'array */
int legge(int **a, int *len) {
  int i;
  scanf("%d", len);
  if(*len <= 0) return 1;

  *a = (int *) malloc(*len * sizeof(int));
  if(*a == NULL) return 1;

  for( i = 0; i < *len; i++ ) 
	  scanf("%d", (*a)+i); 
  return 0;
}

int main() {
  
  int i, n, *A;

  if( legge(&A, &n)) return 1;

  srand(time(NULL));
  quicksort(A, 0, n-1);
  
  /* Stampa l'array ordinato */
  for( i = 0; i < n; i++ ) 
    printf("%d ", A[i]);
	
  return 0;
}
