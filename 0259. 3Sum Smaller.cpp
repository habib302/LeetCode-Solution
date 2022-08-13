class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int n=nums.size();
        
        //base case
        if(n<3)
            return 0;
        
        sort(nums.begin(),nums.end());
        int count=0,left,right;
        
        for(int i=0;i<n-2;i++){
            left=i+1;
            right=n-1;
            
            while(left < right){
                int sum=nums[i]+nums[left]+nums[right];
                
                if(sum < target){
                    
                    //the nums is sorted
                    //so we need to count all the no of pairs between left & right
                    count = count + (right-left);
                    left++;
                }
                else{
                    right--;
                }
            }
        }
        
        return count;
    }
};