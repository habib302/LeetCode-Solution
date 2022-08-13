class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n=nums.size(),count=0;
        
        //base case
        if(n<3)
            return 0;
        
        sort(nums.begin(),nums.end());
        int left,right;
        
        for(int i=2;i<n;i++){
            left=0,right=i-1;
            
            while(left<right){
                
                //a=nums[left] b=nums[right] c=nums[i]
                if(nums[left]+nums[right] >  nums[i]){
                    count= count + (right-left);
                    right--;
                }
                else{
                    left++;
                }
            }
        }
        
        return count;
    }
};