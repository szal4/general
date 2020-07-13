/*Given a binary string s (a string consisting only of '0' and '1's).

Return the number of substrings with all characters 1's.

Since the answer may be too large, return it modulo 10^9 + 7.
////////////////////////////////////////////////////////////////
Input: s = "0110111"
Output: 9
Explanation: There are 9 substring in total with only 1's characters.
"1" -> 5 times.
"11" -> 3 times.
"111" -> 1 time.*/
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
     string s="0110111";
     long res = 0;
        for(int i =0; i < s.length(); ++i)
        {
            long count = 0;
            while(s[i] == '1')
                count++, i++;
            res +=(count*(count+1))/2;
        }
        cout<<res%1000000007;

    return 0;
}
