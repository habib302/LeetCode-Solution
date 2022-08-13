class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int n=nums.size();
        vector<int> res(2,-1);
        
        //lower bound of binary search
        //base case
        if(n==0)
            return res;
        if(n==1 && nums[0]==target){
            res[0]=0;
            res[1]=0;
            return res;
        }
        if(nums[0] > target)
            return res;
        if(nums[n-1] < target)
            return res;
        
        int start=0,end=n-1;
        
        while(start < end){
            int mid= start + (end-start)/2;
            
            if(nums[mid] >= target){
                end = mid;
            }
            else{
                start = mid+1;
            }
        }
        
        //now check we found the lower bound ==target
        if(nums[start]!=target)
            return res;
        
        res[0]=start;
        //we sure we found the lower bound 
        //then check the upper bound
        
        //check upper bound is in the range
        if(nums[n-1]==target){
            res[1]=n-1;
            return res;
        }
        
        start=0, end=n-1;
        while(start < end){
            int mid= start + (end-start)/2;
            
            if(nums[mid] <= target){
                start = mid+1;
            }
            else{
                end = mid;
            }
        }
        
        
        res[1]=start-1;
        return res;
    }
};