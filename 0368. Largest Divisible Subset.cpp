class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        
        //initialize dp with 1...because every element has LIS 1
        vector<int> dp(n,1);
        sort(nums.begin(), nums.end());
        int maxLength=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i] % nums[j]==0){
                    
                    //if we found LIS
                    if(dp[i] < dp[j]+1){
                        dp[i] = dp[j]+1;
                    }
                }
            }
            
            //update the max length variable
            maxLength = max(maxLength, dp[i]);
        }
        
        int prev=-1;
        vector<int> res;
        
        //now build the result
        for(int i=n-1;i>=0;i--){
            if(maxLength==dp[i] &&(prev==-1 || prev%nums[i]==0)){
                res.push_back(nums[i]);
                maxLength--;
                prev=nums[i];
            }
        }
        
        return res;
    }
};