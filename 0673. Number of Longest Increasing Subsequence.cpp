class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        
        vector<int> dp(n,1);  //for LIS
        vector<int> cnt(n,1); //for LIS count 
        int maxLength=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j] < nums[i]){
                    
                    //if we found 1st LIS and reassign the count
                    //update the LIS & assign to cnt
                    if(dp[i] < dp[j]+1){
                        dp[i] = dp[j]+1;
                        cnt[i] = cnt[j];
                    }
                    //for the second or later LIS
                    else if(dp[i]==dp[j]+1){
                        cnt[i] = cnt[i] + cnt[j];
                    }
                }
            }
            //every time update the maxLength
            maxLength=max(maxLength,dp[i]);
        }
        
        int res=0;
        //count the result
        for(int i=0;i<n;i++){
            if(maxLength==dp[i]){
                res = res + cnt[i];
            }
        }
        
        return res;
    }
};