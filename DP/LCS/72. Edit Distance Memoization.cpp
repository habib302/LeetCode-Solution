class Solution {
public:
    //memoization
    int dp[502][502];
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof dp);
        return helper(0,0,word1,word2);
    }
    
    int helper(int i,int j,string& s1,string& s2){
        if(dp[i][j] != -1) return dp[i][j];
        
        //base case 1
        if(i==s1.size()) return s2.size()-j;
        
        //base case 2
        if(j==s2.size()) return s1.size()-i;
        
        //choice diagaram
        if(s1[i]==s2[j]){
            return dp[i][j]=helper(i+1,j+1,s1,s2);
        }else{
            int op1 =  1 + helper(i,j+1,s1,s2);    //insert
            int op2 =  1 + helper(i+1,j,s1,s2);    //delete
            int op3 =  1 + helper(i+1,j+1,s1,s2);  //replace
            
            return dp[i][j]=min(op1, min(op2,op3));
        }
        
    }
};