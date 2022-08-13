class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        
        //base case
        if(n<3)
            return -1;
        
        int left,right,prevDiff=INT_MAX;
        int res=0;
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<(n-2);i++){
            left=i+1;
            right=n-1;
            
            while(left<right){
                
                int sum=nums[i]+nums[left]+nums[right];
                
                int currDiff=abs(target-sum);
                
                if(sum==target) 
                    return sum;
                else if(sum < target) 
                    left++;
                else 
                    right--;
                
                if(currDiff < prevDiff){
                    prevDiff=currDiff;
                    res = sum;
                }
            }
        }
        return res;
    }
};