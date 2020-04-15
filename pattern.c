#include <stdio.h>
int main()
{
  int n;
  scanf("%d",&n);
  int pp=-1;
  int next_value=n+1;
  int count=0;
  for(int k=0;k<(n*2)-1;k++){ //loop for rows
      if(k<n){ 
          for(int i=0;i<k;i++){
              printf("%d ",n-i);
              next_value=n-i;
              count++;
          }
          for(int j=1;j<=((n*2)-1)-(2*count);j++){
              printf("%d ",next_value-1);
          }
          for(int l=0;l<count;l++){
              printf("%d ",next_value+l);
          }
      }
    if(k>=n){
        pp++;
        for(int p=0;p<n-1-pp;p++){
            printf("%d ",n-p);
            count++;
            next_value=n-p;
        }
        for(int q=1;q<=((2*n)-1)-(2*count);q++){
            printf("%d ",next_value);
        }
        for(int r=0;r<count;r++){
            printf("%d ",next_value+r);
        }
    }
    printf("\n");
    count=0;
  }//loop
    return 0;
}
