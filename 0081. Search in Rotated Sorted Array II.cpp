class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        
        int start=0,mid=0,end=n-1;
        
        while(start <= end){
            
            //skip duplicate
            while(start<end && nums[start]==nums[start+1]) 
                start++;   
            while(start<end && nums[end]==nums[end-1])     
                end--;
            
            mid = start + (end-start)/2;
            
            if(nums[mid]==target)
                return true;
            //assume left part is sorted
            else if(nums[start] <= nums[mid]){
                
                if(nums[start]<=target && target<=nums[mid])
                    end=mid-1;
                else 
                    start=mid+1;
            }
            //assume right part is sorted
            else{
                
                if(nums[mid]<=target && target<=nums[end])
                    start=mid+1;
                else 
                    end=mid-1;
            }
        }
        
        return false;
    }
};