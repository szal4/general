//calcutation of Greatest common Divisor
//common divisors of a and b are exactly the same as the common divisors of a' and b.
//gdc(a,b)=gdc(a',b)=gdc(b,a')
//where a' is the remainder when a is divided by b i.e. a%b
//Therefore,the greatest common divisor of a and b is the greatest common divisor of a' and b.
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int gdc(int a,int b) {
   if(b==0){ 
       return a;
   }
   return gdc(b,a%b);
}
int main(){
    int a,b;
    cin>>a>>b;
    cout<<gdc(a,b);
    return 0;
}
