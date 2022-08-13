class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        
        int n=nums.size();
        
        //base case
        if(n<2)
            return nums;
        
        int left=0,right=n-1;
        
        while(left < right){
            
            if(nums[left]%2==0){
                left++;
            }
            else if(nums[right]%2==1){
                right--;
            }
            else{
                swap(nums[left],nums[right]);
            }
        }
        
        return nums;
    }
};