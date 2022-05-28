class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
        if(nums.size()==1) return nums[0]*1.0;
        
        int left=0,right=0,sum=0;
        
        double res=INT_MIN;
        
        while(right < nums.size()){
            
            sum = sum + nums[right];
            
            if(right >= k-1){
                
                res = max(res, ( (sum*1.0)/ (k*1.0) ) );
                
                sum = sum - nums[left];
                
                left++;
            }
            
            right++;
        }
        
        return res;
    }
};