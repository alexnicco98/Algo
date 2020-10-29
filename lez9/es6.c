#include <stdio.h>

int max(int a,int b){
       if(a>b)
             return a;
       return b;
}

int cutroad(int a[],int n){
      int q,i;
      if(n==0)
            return 0;
      q=-1;
      for(i=0;i<n;i++)
            q=max(q,a[i]+cutroad(a,n-i-1));
      return q;
}

void extcutroad(int r[],int s[],int a[],int n){
     int j,i,q;
     for(j=0;j<n;j++){
           q=-1;
           for(i=0;i<=j;i++)
                  if(q<a[i]+r[j-i-1]){
                         q=a[i]+r[j-i-1];
                         s[j]=i+1;
                  }
           r[j]=q;
    }
}

void print_extcutroad(int r[],int s[],int n){
      n--;
      if(n==0)
           printf("%d",s[n]);
      while(n>0){
           printf("%d ",s[n]);
           n=n-s[n];
      }
      printf("\n");
}

int main(){
      int i,x,n;
      scanf("%d",&n);
      int a[n],r[n],s[n];
      for(i=0;i<n;i++)
            scanf("%d",&a[i]);
      printf("%d\n",cutroad(a,n));
      extcutroad(r,s,a,n);
      print_extcutroad(r,s,n);
      
}





