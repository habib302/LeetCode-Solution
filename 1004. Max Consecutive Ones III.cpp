class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
      int left=0, right=0,n=nums.size(),res=0, zeroCount=0;
        
        for( right=0; right<n;right++){
            
            if(nums[right]==0){
                zeroCount++;
            }
            
            while(zeroCount > k){
                
                if(nums[left]==0){
                    zeroCount--;
                }
                
                left++;
            }
            
            res=max(res, right-left+1);
        }
        
        return res;
    }
};