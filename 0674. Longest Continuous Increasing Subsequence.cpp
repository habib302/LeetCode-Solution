class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        
        int n=nums.size();
        
        //base case
        if(n<=1) return n;
        
        int currLength=1,maxLength=1;
        
        for(int i=1;i<n;i++){
            
            //check continuous and update the maxLength
            if(nums[i-1]<nums[i]){
                currLength++;
                maxLength = max(currLength, maxLength);
            }
            //else initialize currLength to 1
            else{
                currLength = 1;
            }
        }
        
        return maxLength;
    }
};