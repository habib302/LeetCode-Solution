class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        
        int n=nums.size();
        //base case
        if(n==1) return nums;
        
        int left=0,right=n-1;
        
        while(left<right){
            
            if(nums[right]%2==0){
                if(nums[left]%2==1){
                    swap(nums[left], nums[right]);
                    left++;
                    right--;
                }
                else{
                    left++;
                }
            }
            else{
                right--;
            }
        }
        
        return nums;
    }
};