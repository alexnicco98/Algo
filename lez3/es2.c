#include <stdio.h>
#include <stdlib.h>

   int main(){
    int c,d,i=0,j=0,el=0;   
    scanf("%d",&c); 
    int a[c];   
    for(i=0;i<c;i++)
        scanf("%d",&a[i]); 
          
    scanf("%d",&d); 
    int b[d];
    for(i=0;i<d;i++)
        scanf("%d",&b[i]);                
    
    i=0;
    j=0;
    while(i<c&&j<d){
        if(a[i]==b[j]){
            el++;
            j++;
            i++;
        }
        else{
           if(a[i]<b[j])i++;
           else j++;
        }
    }

    printf("%d\n",el);
       
 
    return 0;
   }







