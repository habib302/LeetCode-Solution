class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int j=0,n=nums.size();
        
        for(int i=1;i<n;i++){
            
            if(nums[i-1] != nums[i]){
                nums[j]=nums[i-1];
                j++;
            }
        }
        
        //last case need to handle
        nums[j]=nums[n-1];
        j++;
        
        return j;
    }
};	