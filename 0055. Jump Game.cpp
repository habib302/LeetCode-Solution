class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int n=nums.size();
        int lastIndex=n-1,maxJump=0;
        
        //check i=0....maxJump
        for(int i=0;i<=maxJump;i++){
            
            maxJump= max(maxJump, i+nums[i]);
            
            if(maxJump >= lastIndex){
                return true;
            }
        }
        
        return false;
    }
};