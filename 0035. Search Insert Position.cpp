class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int n=nums.size();
        int start=0,end=n-1;
        
        //base case
        if(nums[0] > target)
            return 0;
        if(nums[n-1] < target)
            return n;
        
        //lower bound
        //we need to check base case first
        //so that we can sure target is between the range
        while(start < end){
            int mid = start + (end-start)/2;
            
            if(nums[mid] >= target){
                end = mid;
            }
            else{
                start = mid+1;
            }
        }
        
        return start;
    }
};