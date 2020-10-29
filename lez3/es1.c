#include <stdio.h>
#include <stdlib.h>

 void merge(int a[],int l,int m,int r){
      int i=l,j=m+1,k=l,b[r];
      while((i<=m)&&(j<=r)){
           if(a[i]<=a[j]){
                b[k]=a[i];
                i++;
                k++;
           }
           else{
                b[k]=a[j];
                j++;
                k++;
           }
      }
      while(i<=m){
           b[k]=a[i];
           i++;
           k++;
      }
      while(j<=r){
           b[k]=a[j];
           j++;
           k++;
      }
      for(i=l;i<=r;i++)
           a[i]=b[i]; 
   // for(i=l;i<r;i++)
     // printf("%d\n",a[i]);
   
 }

 void mergesort(int a[],int i,int c){
      int m;
      if(i<c){
           m=(i+c)/2;
           mergesort(a,i,m);
           mergesort(a,m+1,c);
           merge(a,i,m,c);   //
      }
      
 }
         
 int ricbin(int a[],int el,int i, int j){
     int m;
     if(j<i)return -1;
     else m=(i+j)/2;
     if(a[m]==el) return m;
     if(a[m]>el) return ricbin(a,el,i,m-1);
     else return ricbin(a,el,m+1,j);
     

 }    


 
   int main(){
    int c,d,i=0,el=0;   
    scanf("%d",&c); 
    int a[c];   
    for(i=0;i<c;i++)
        scanf("%d",&a[i]); 
          
    scanf("%d",&d); 
    int b[d];
    for(i=0;i<d;i++)
        scanf("%d",&b[i]); 
    mergesort(a,0,c-1);
    mergesort(b,0,d-1);                
    
    for(i=0;i<c;i++)
        if(ricbin(b,a[i],0,d-1)!=-1) el++;

    printf("%d\n",el);
       
 
    return 0;
   }













