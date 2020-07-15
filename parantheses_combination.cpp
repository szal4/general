//Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        p(ans,"",0,0,n);
        return ans;  
    }
    void p(vector<string>& v,string str,int left,int right,int n){
       if(left==n&&right==n){
           v.push_back(str);
           return;
       }
       else if(left==right)
           p(v,str+"(",left+1,right,n);
        else if(left==n)
            p(v,str+")",left,right+1,n);
        else{
            p(v,str+"(",left+1,right,n);
             p(v,str+")",left,right+1,n);
        }                  
    }
    
};
