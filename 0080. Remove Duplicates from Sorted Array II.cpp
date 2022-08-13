class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        
        //base case
        if(n<3)
            return n;
        
        int j=0;
        for(int i=2;i<n;i++){
            if(nums[i-2]!=nums[i]){
                nums[j]=nums[i-2];
                j++;
            }
        }
        
        //handle last two element
        nums[j]=nums[n-2];
        j++;
        nums[j]=nums[n-1];
        j++;
        
        return j;
    }
};