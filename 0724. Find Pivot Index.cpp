class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int n=nums.size();
        
        //base case
        if(n==1)
            return 0;
        
        int sum=0,prefixSum=0;
        
        for(int num: nums){
            sum = sum+num;
        }
        
        
        for(int i=0;i<n;i++){
            
            
            sum = sum - nums[i];
            
            if(prefixSum==sum){
                return i;
            }
            
            prefixSum = prefixSum+nums[i];
        }
        
        return -1;
    }
};