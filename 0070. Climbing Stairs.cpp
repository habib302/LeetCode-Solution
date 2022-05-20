class Solution {
public:
    int dp[46];
    int climbStairs(int n) {
        memset(dp,-1,sizeof dp);
        return helper(n);
        
    }
    
    int helper(int n){
        
        //base case
        if(n==1) return 1;
        if(n==2) return 2;
        if(n==3) return 3;
        
        if(dp[n] != -1) return dp[n];
        
        return dp[n]=helper(n-1)+helper(n-2);
    }
};