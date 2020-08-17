/*
  -------------------Unlocker TCS codevita season 9------------------


Problem Description
A locker is comprised of one or more layers. Each layer can be rotated only in one direction. Odd numbered layers rotate in anti-clockwise direction (left to right), and even numbered layers rotate in clockwise direction (right to left).

You are given a locker, in the form of a matrix. The matrix will be rectangular in shape. The outer most layer of this matrix is layer1. In context of the diagram below, the numbers painted in red are layer1 and the inner numbers constitute layer2. Bigger matrices will have more layers.

One rotation defined as a given number moving in the neighbouring spot i.e. one spot left for clockwise rotation and one spot right for anti-clockwise rotation.

Number of rotations for each layer required to unlock the locker will be provided as input. Print the final unlocked matrix as output.

com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@134a2ab9:image1.png

com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@134a2ab9:image2.png

Constraints
1 < M, N <= 300

0 <= Numbers in matrix < 100

1 <= Number of rotations <= 10^9

M%2=0 && N%2=0

Input
First line contains two space separated integer M and N which denotes the number of rows and number of columns, respectively

Next M lines contain N space separated integers depicting the locked matrix

Last line contains L space separated integers, where L is the number of layers. Each number on this line denotes the number of rotations for every layer from 1 to L

Output
Print unlocked matrix

Time Limit
2

Examples
Example 1

Input

2 2

1 2

3 4

2

Output

4 3

2 1

Explanation:

There is only one layer. So, we have to rotate it in anti-clockwise direction with 2 rotations.

com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@134a2ab9:image3.png

Example 2

Input

4 4

1 2 3 4

2 3 4 5

2 4 5 6

2 3 4 5

2 2

Output

3 4 5 6

2 5 4 5

1 4 3 4

2 2 2 3

Explanation:

Here we have to rotate layer1 in anti-clockwise direction with 2 rotations, and layer2 clockwise with 2 rotations
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m,n;
    cin>>m>>n;
    vector<vector<int>> v(m,vector<int>(n));//main vector
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>v[i][j];
        }
    }
    vector<int> r(min(m,n)/2,0);//we will have total layer = min(m,n)/2
    for(int i=0;i<min(m,n)/2;i++){
        cin>>r[i];
    }
    //all input work is done till here
    int i=0,j=0,l=0,rt=n-1,t=0,b=m-1,xx,temp;
    for(int k=0;k<(int)r.size();k++){ 
        xx=r[k];
        xx=xx%((2*(rt-l))+(2*(b-t)));  //to reduse multipe rotation,after ((2*(rt-l))+(2*(b-t)) rotation it will come to its origional location
        if(k%2!=0){ //clock-wise rotation for 2,4,6...layer here indext 1,3.. means layer 2,4..
             for(int q=0;q<xx;q++){
                 temp=v[i][j]; //for evey new rotation we want temp to have v[i][j] value
               while(j<rt){
                   swap(v[i][j+1],temp);
                   j++;
               }
               while(i<b){
                   swap(v[i+1][j],temp);
                   i++;
               }
               while(j>l){
                   swap(v[i][j-1],temp);
                   j--;
               }
               while(i>t){
                   swap(v[i-1][j],temp);
                   i--;
               }
             }
        }
        else{ //anti clockwise rotation for 1,3,5....layer here indet 0,2.. means layer 1,3..
            for(int q=0;q<xx;q++){
                temp=v[i][j];
                while(i<b){
                    swap(v[i+1][j],temp);
                    i++;
                }
                while(j<rt){
                    swap(v[i][j+1],temp);
                    j++;
                }
                while(i>t){
                    swap(v[i-1][j],temp);
                    i--;
                }
                while(j>l){
                    swap(v[i][j-1],temp);
                    j--;
                }
            }
        }
        i++;
        j++;
        l++;
        t++;
        rt--;
        b--;
    }
    //logic work end
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
