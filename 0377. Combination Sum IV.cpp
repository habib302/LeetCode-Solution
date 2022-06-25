class Solution {
public:
    int dp[1002];
    
    int combinationSum4(vector<int>& nums, int target) {
        
        memset(dp, -1, sizeof dp);
        
        return helper(target,nums);
        
    }
    
    int helper(int target, vector<int> &nums){
        
        //base case
        if(target == 0) return 1;
        if(target < 0) return 0;
        
        if(dp[target] != -1) return dp[target];
        
        int count=0;
        
        for(int i=0;i<nums.size();i++){
            count = count + helper(target-nums[i], nums);
        }
        
        return dp[target]=count;
    }
};