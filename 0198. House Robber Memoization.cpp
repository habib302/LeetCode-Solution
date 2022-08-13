class Solution {
public:
    //memoization
    int dp[102];
    int rob(vector<int>& nums) {
        int n=nums.size();
        memset(dp,-1,sizeof dp);
        return helper(n-1,nums);
    }
    
    int helper(int n,vector<int>& nums){
        //base case
        if(n<0) 
			return 0;
        
        if(dp[n] != -1) 
			return dp[n];
        
        //choice diagram
        int op1 = helper(n-2,nums) + nums[n];
        int op2 = helper(n-1,nums);
        
        return dp[n]=max(op1,op2);
    }
};
