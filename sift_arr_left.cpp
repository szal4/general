int gcdd(int a,int b){
    if(b==0)
    return a;
    return gcdd(b,a%b);
}
// Complete the rotLeft function below.
vector<int> rotLeft(vector<int> a, int d) {
d=d%a.size();
int j,temp;
int gcd=gcdd(a.size(),d);
for(int i=0;i<gcd;i++){
    j=i;
    temp=a[j];
    while(1){
        j=j-d;
        if(j<0)
        j=a.size()+j; 
        if(j==i)
        break;  
        swap(a[j],temp);
     }
     a[j]=temp;
}
return a;
}
