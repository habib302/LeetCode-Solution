class Solution {
public:
    int dp[102][102];
    int uniquePaths(int m, int n) {
        memset(dp, -1, sizeof dp);
        return helper(m-1,n-1);
    }
    
    int helper(int i,int j){
        //base case
        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int op1=helper(i-1,j);
        int op2=helper(i,j-1);
        
        return dp[i][j]=op1+op2;
    }
};