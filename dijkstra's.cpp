#include <iostream>
#include<bits/stdc++.h>
using namespace std;
void sortest_path(vector<vector<int>> v,int n){
    vector<int> d(n,INT_MAX); //distance array this will keep on updating
    d[0]=0;
    vector<int> visited(n,false);
    int mn=0,mnv;
    
    for(int ii=0;ii<n-1;ii++){
        visited[mn]=true;
       for(int i=0;i<n;i++){
           if(!visited[i] && v[mn][i]!=-1 && d[i]>d[mn]+v[mn][i]){
               d[i]=d[mn]+v[mn][i];
           }
       }
       mnv=INT_MAX;
       for(int j=0;j<n;j++){
           if(!visited[j] && d[j]<=mnv){
             mnv=d[j];
             mn=j;
           }
       }
    }
    
    for(int i=0;i<n;i++){
        cout<<i<<"-"<<d[i]<<endl;
    }
}
int main()
{
    int n,t,x,y,c;
    cout<<"Enter total nodes in graph"<<endl;
    cin>>n;
    vector<vector<int>> v(n,vector<int>(n,-1));
    cout<<"Enter total edges in graph"<<endl;
    cin>>t;
    cout<<"Enter sorce edges,destination edge and cost for all edges"<<endl;
    for(int i=0;i<t;i++){
     cin>>x>>y>>c;
     v[x][y]=c;
    }
  
    sortest_path(v,n);
    return 0;
}
