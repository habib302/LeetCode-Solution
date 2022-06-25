//1year age ai solution ta accept hoito
//akhn new test case dice tai ar kaj kore na
//TC=O(n^2)
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
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
            
            if(maxLength>=3)
                return true;
        }
        
        
        return false;
    }
};

========================================================

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        
        //base case
        if(n<3) return false;
        
        int i=INT_MAX, j=INT_MAX;
        
        for(int index=0;index<n;index++){
            
            if(nums[index] <= i){
                i=nums[index];
            }
            else if(nums[index] <= j){
                j=nums[index];
            }
            else{
                return true;
            }
        }
        
        return false;
    }
};