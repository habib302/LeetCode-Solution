class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> res;
        int n=nums.size(),left,right,sum;
        
        //base case
        if(n<2) return res;
        
        sort(nums.begin(), nums.end());
        
        for(int i=0;i<n-2;i++){
            
            //handle duplicate
            if(i>0 && nums[i]==nums[i-1]) continue;
            
            left=i+1;
            right=n-1;
            
            while(left < right){
                
                sum = nums[i]+nums[left]+nums[right];
                
                if(sum==0){
                    res.push_back({nums[i],nums[left],nums[right]});
                    
                    //handle left duplicate
                    while(left<right && nums[left]==nums[left+1]){
                        left++;
                    }
                    
                    //handle right duplicate
                    while(left<right && nums[right]==nums[right-1]){
                        right--;
                    }
                    
                    left++;
                    right--;
                }
                else if(sum >0){
                    right--;
                }
                else{
                    left++;
                }
            }
        }
        
        return res;
    }
};