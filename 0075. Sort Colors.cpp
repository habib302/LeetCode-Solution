class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int n=nums.size(),left,mid,right;
        
        //left to trase zero
        //mid to trase one
        //right to trase two
        //only check nums[mid]
        
        left=0,mid=0,right=n-1;
        
        while(mid<=right){
            
            if(nums[mid]==0){
                swap(nums[left],nums[mid]);
                left++;
                mid++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else{
                swap(nums[mid],nums[right]);
                right--;
            }
        }
    }
};