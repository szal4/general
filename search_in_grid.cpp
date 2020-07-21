/*Given a 2D board and a word, find if the word exists in the grid.
The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. 
The same letter cell may not be used more than once.
Example
board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.*/
class Solution {
public:
     bool fun(vector<vector<char>> v,string word,int i,int j,int k){
         bool x=0;
         if(k==word.size())
            return 1;  
         if(i-1>=0&&v[i-1][j]==word[k]){
            v[i-1][j]='#';
            x=x||fun(v,word,i-1,j,k+1);
             v[i-1][j]=word[k];
         }
         if(j+1<v[0].size()&&v[i][j+1]==word[k]){
            v[i][j+1]='#';
            x=x||fun(v,word,i,j+1,k+1);
             v[i][j+1]=word[k];
         }
         if(i+1<v.size()&&v[i+1][j]==word[k]){
            v[i+1][j]='#';
            x=x||fun(v,word,i+1,j,k+1);
             v[i+1][j]=word[k];
         }
         if(j-1>=0&&v[i][j-1]==word[k]){
            v[i][j-1]='#';
            x=x||fun(v,word,i,j-1,k+1);
             v[i][j-1]=word[k];
         }
         return x;    
     }
    bool exist(vector<vector<char>>& board, string word) {
        bool ans=0;
        char ch;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0]){
                    board[i][j]='#'; 
                    ans=ans||fun(board,word,i,j,1);
                    board[i][j]=word[0];
                }
                if(ans==1)
                    break;
            }
            if(ans==1)
                break;
        }
        return ans;
    }
};
