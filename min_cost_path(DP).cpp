//min_cost_path in grid (you can only traverse down,right and diagonally lower cell)
#include<bits/stdc++.h>
using namespace std;
int min(int a,int b,int c){//no syntex for finding min of 3 element 
    if(b<c){
        return b<a? b:a;
    }
    else{
        return c<a? c:a;
    }
}
int min_path(int a[3][3],int r,int c){
    int dp[r][c];
    dp[0][0]=a[0][0];
    for(int i=1;i<r;i++){
        dp[i][0]=dp[i-1][0]+a[i][0];
    }
    for(int i=1;i<c;i++){
        dp[0][i]=dp[0][i-1]+a[0][i];
    }
    for(int j=1;j<r;j++){
        for(int k=1;k<c;k++){
            dp[j][k]=min(dp[j-1][k-1],dp[j-1][k],dp[j][k-1])+a[j][k];
        }
    }
    return dp[r-1][c-1];
}
int main()
{
    int arr[3][3]={{1,2,3},{4,8,2},{1,5,3}};
    cout<<min_path(arr,3,3);
    return 0;
}
