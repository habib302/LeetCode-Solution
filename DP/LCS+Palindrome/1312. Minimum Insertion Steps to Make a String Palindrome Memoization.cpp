class Solution {
public:
    //memoization
    int dp[1001][1001];
    int minInsertions(string s) {
        string s2=s;
        reverse(s2.begin(),s2.end());
        memset(dp,-1,sizeof dp);
        int LCS=helper(0,0,s,s2);
        return (s.size()-LCS);
    }
    
    //LCS memoization
    int helper(int i,int j,string& s1, string& s2){
        if(dp[i][j] != -1 ) return dp[i][j];
        
        //base case 1
        if(i==s1.size()) return 0;
        
        //base case 2
        if(j==s2.size()) return 0;
        
        
        //choice diagram
        if(s1[i]==s2[j]){
            return dp[i][j] = 1 + helper(i+1,j+1,s1,s2);
        }else{
            int op1 = helper(i+1,j,s1,s2);
            int op2 = helper(i,j+1,s1,s2);
            
            return dp[i][j]=max(op1,op2);
        }
    }
};