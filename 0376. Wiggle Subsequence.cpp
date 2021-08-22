// using diff, prevDiff
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size(),count=1,prevDiff=0,diff=0;
        
        if(n<2) return n;
        
        for(int i=1;i<n;i++){
            diff = nums[i]-nums[i-1];
            
            if((diff>0 && prevDiff<=0) || (diff<0 && prevDiff>=0)){
                count++;
                prevDiff=diff;
            }
        }
        
        return count;
    }
};