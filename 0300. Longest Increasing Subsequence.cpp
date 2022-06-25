class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        
        //initialize dp with 1...because every element has LIS 1
        vector<int> dp(n,1);
        int maxLength=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j] < nums[i]){
                    
                    //if we found LIS
                    if(dp[i] < dp[j]+1){
                        dp[i] = dp[j]+1;
                    }
                }
            }
            
            //update the max length variable
            maxLength = max(maxLength, dp[i]);
        }
        
        return maxLength;
    }
};