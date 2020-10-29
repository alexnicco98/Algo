#include <stdio.h>


 void somma(int a[],int n){
    int i,j=0,somma=0;
    while(a[j]<=0) j++;
    for(i=j;i<n;i++){                      
        somma+=a[i];
        if(somma+a[i+1]<somma)break;
        if(somma<=0) somma=0;                                   
    }
    
    printf("%d\n",somma);
   
}
 
   int main(){
    int n,i;
    scanf("%d",&n);  
   int a[n];  
    for(i=0;i<n;i++)
        scanf("%d",&a[i]); 
                              
    somma(a,n);
 
    return 0;
   }
