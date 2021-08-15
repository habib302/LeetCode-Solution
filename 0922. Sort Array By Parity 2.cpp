//two pointer solution
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        
        int even=0,odd=1,n=nums.size();
        
        while(even<n && odd<n){
            
            //continue even
            while(even<n && nums[even]%2==0){
                even= even+2;
            }
            
            //continue odd
            while(odd<n && nums[odd]%2==1){
                odd= odd+2;
            }
            
            if(even<n && odd<n){
                swap(nums[even],nums[odd]);
            }
        }
        
        return nums;
    }
};