class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
      int n=nums.size(),maxLength=0,count=0,start=0;
      
      for(int end=0;end<n;end++){
        
        //step1: count zero
        if(nums[end]==0) count++;
        
        //step2: update start until count<=k
        while(count>k){
          if(nums[start]==0) count--;
          start++;
        }
        
        //step3:  update max length 
        maxLength=max(maxLength, end-start+1);
      }
      
      return maxLength;
    }
};