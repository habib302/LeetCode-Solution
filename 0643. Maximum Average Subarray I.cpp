class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
        double res=INT_MIN;
        
        int left=0,right=0,n=nums.size(),sum=0;
        
        for( right=0; right<n ;right++){
            
            //update the sum
            sum = sum + nums[right];
            
            if(right >= k-1){
                //update the res
                double avg = sum / (k*1.0);
                res = max(res,avg);
                
                //release the nums[left]
                //update left by 1
                sum = sum - nums[left];
                left++;
            }
        }
        
        return res;
    }
};