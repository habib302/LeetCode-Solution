class Solution {
public:
    int jump(vector<int>& nums) {
        
        int n=nums.size();
        
        int jump=0,maxReach=0,currReach=0;
        
        for(int i=0;i<n-1;i++){
            
            //step1: update the maxReach
            maxReach = max(maxReach, nums[i]+i);
            
            //step2: check if i==currReach
            //already explore all the element
            if(i==currReach){
                currReach=maxReach;
                jump++;
            }
                
        }
        
        return jump;
    }
};