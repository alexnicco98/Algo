#include <stdio.h>

void Merge(int a[],int b[],int c[],int n,int m){
       int i=0,j=0,k=0;       
       while(i<n && j<m)
             if(a[i]<=b[j]){
                   c[k]=a[i];
                   i++;
                   k++;
             }
             else{
                   c[k]=b[j];
                   j++;
                   k++;
             }
       while(i<n){
            c[k]=a[i];
            i++;
            k++;
       }
       while(j<m){
            c[k]=b[j];
            j++;
            k++;
       }            
}
      

int main(){
      int x,n,m,i;
      scanf("%d",&n); 
      int a[n];        
      for(i=0;i<n;i++){
            scanf("%d",&x);
            a[i]=x;
      }
      scanf("%d",&m); 
      int b[m];  
      for(i=0;i<m;i++){
            scanf("%d",&x);
            b[i]=x;
      }     
      int c[n+m];
      Merge(a,b,c,n,m);
      for(i=0;i<n+m;i++)
            printf("%d\n",c[i]);             
           
      
      return 0;
      
}
