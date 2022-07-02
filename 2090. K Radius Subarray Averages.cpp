class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        
        int n=nums.size();
        vector<int> res(n,-1);
        
        //base case
        if(k == 0)
            return nums;
        if(k > ceil(n/2.0))
            return res;
        
        int left=0,right=0;
        long sum=0;
        
        for(right=0; right<n; right++){
            sum = sum + nums[right];
            
            //check condition
            if(right >= k*2){
                int avg = sum / ((k*2)+1);
                res[right-k]=avg;
                
                //release from sum
                //increment left by 1
                sum = sum - nums[left];
                left++;
            }
        }
        
        return res;
    }
};