method 1: general
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count=0,maxCount=0,n=nums.size();
        
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                count=0;
            }
            else{
                count++;
            }
            
            maxCount = max(count,maxCount);
        }
        
        return maxCount;
    }
};
------------------------------------------------------------
method 2: sliding window
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int left=0, right=0,n=nums.size(),res=0, zeroCount=0,k=0;
        
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