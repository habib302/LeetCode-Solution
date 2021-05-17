class Solution {
public:
    //memoization
    int dp[1002];
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp,-1,sizeof dp);
        return helper(cost.size(),cost);
    }
    
    int helper(int n,vector<int>& cost){
        //base case 1
        if(n==0) return 0;
        
        //base case 2
        if(n==1) return 0;
        
        if(dp[n] != -1) return dp[n];
        
        //choice diagram
        int op1 = helper(n-1,cost) + cost[n-1];
        
        int op2 = helper(n-2,cost) + cost[n-2];
        
        return dp[n]=min(op1,op2);
    }
};