class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int n=nums.size();
        int start=0,end=n-1,mid;
        
        //base case
        if(n==1) 
			return 0;
        
        while(start <= end){
            
            //find mid
            mid = start + (end-start)/2;
            
            if(mid>0 && mid<(n-1)){
                if(nums[mid-1]<nums[mid] && nums[mid]>nums[mid+1] ){
                    return mid;
                }
                else if(nums[mid] < nums[mid+1]){
                    start=mid+1;
                }
                else{
                    end=mid-1;
                }
            }
            //1st element
            else if(mid==0){
                if(nums[mid] > nums[mid+1]){
                    return 0;
                }
                else return 1;
            }
            //last element
            else if(mid==n-1){
                if(nums[mid-1] < nums[mid]){
                    return n-1;
                }
                else return n-2;
            }
        }
        
        return -1;
    }
};