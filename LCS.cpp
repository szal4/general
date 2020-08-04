/*Given two strings text1 and text2, return the length of their longest common subsequence.

A subsequence of a string is a new string generated from the original string with some characters(can be none) deleted without changing the relative order of the remaining 
characters. (eg, "ace" is a subsequence of "abcde" while "aec" is not). A common subsequence of two strings is a subsequence that is common to both strings.
If there is no common subsequence, return 0.
Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.
Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.*/
//quetion similar to LCS(longest comman subsequence)---->>>>
//1) Minimum insertion and deletion need to convert string a into b is insertion=b.size()-LCS and deletion=a.size()-LCS total a.size()+b.size()-2*LCS;
//2) Longest palindrom subsequence (ex:string a="agbcba" so longest comman subsequence is "abcba") is equal to LCS between a and reverse of a
//3) Minimum number of deletion in a string to make is palindrom is s.size()-(LCS between a and reverse of a)
//4) sortest comman Supersequence(i.e. both string a anad b is prsent in ans string ex: a="acbcf" b="abcdaf" so ans="acbcdaf") isa.size()+b.size()-LCS
//function is writtern
int longestCommonSubsequence(string text1, string text2) {
       int dp[text1.size()+1][text2.size()+1];
       for(int i=0;i<=text1.size();i++){
           for(int j=0;j<=text2.size();j++){
               if(i==0||j==0)
                   dp[i][j]=0;
           }
       }
       for(int i=1;i<=text1.size();i++){
          for(int j=1;j<=text2.size();j++){
            if(text1[i-1]==text2[j-1])
                dp[i][j]=1+dp[i-1][j-1];
             else
                 dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
         }
       }
        return dp[text1.size()][text2.size()];
    }
