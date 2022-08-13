class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> res;
        int n=nums.size(),left,right,sum,target=0;
        
        //base case
        if(n<3) 
			return res;
        
        
        sort(nums.begin(), nums.end());
        
        for(int i=0;i<n-2;i++){
            
            //handle duplicate
            if(i>0 && nums[i]==nums[i-1]) 
                continue;
            
            left=i+1;
            right=n-1;
            int newTarget=target-nums[i];
            while(left < right){
                
                sum = nums[left]+nums[right];
                
                if(sum==newTarget){
                    res.push_back({nums[i],nums[left],nums[right]});
                    
                    //update left
                    //handle left duplicate
                    while(left<right && nums[left]==nums[left+1]){
                        left++;
                    }
                    left++;
                    
                    //update right
                    //handle right duplicate
                    while(left<right && nums[right]==nums[right-1]){
                        right--;
                    }
                    right--;
                }
                else if(sum < newTarget){
                    left++;
                }
                else{
                    right--;
                }
            }
        }
        
        return res;
    }
};