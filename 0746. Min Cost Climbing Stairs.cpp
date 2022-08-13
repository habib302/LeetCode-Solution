class Solution {
public:
    int dp[1001];
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        memset(dp,-1,sizeof dp);
        return min(helper(n-1,cost), helper(n-2,cost));
    }
    
    int helper(int n, vector<int>& cost){
        
        //base case
        if(n==0) 
			return cost[0];
        if(n==1) 
			return cost[1];
        
		//check in dp table
        if(dp[n] != -1) 
			return dp[n];
        
        int op1 = helper(n-1, cost);
        int op2 = helper(n-2, cost);
        
        return dp[n]=min(op1,op2)+cost[n];
    }
};