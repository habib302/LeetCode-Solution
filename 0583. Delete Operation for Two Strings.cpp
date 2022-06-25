class Solution {
public:
    int dp[502][502];
    int minDistance(string word1, string word2) {
        memset(dp, -1, sizeof dp);
        int LCS = helper(0,0,word1,word2);
        
        int res = (word1.size()+word2.size()) - (2*LCS);
        return res;
    }
    
    int helper(int i,int j,string& s1,string& s2){
        //base case
        if(i==s1.size() && j==s2.size()) return 0;
        if(i==s1.size()) return 0;
        if(j==s2.size()) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        //match
        if(s1[i]==s2[j]){
            return dp[i][j]=1+helper(i+1,j+1,s1,s2);
        }
        else{
            int op1 = helper(i+1, j  ,s1,s2);
            int op2 = helper(i  , j+1,s1,s2);
            return dp[i][j]=max(op1,op2);
        }
    }
};