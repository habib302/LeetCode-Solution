class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
      int n=nums.size();
      vector<int> res;
      
      //base case
      if(n<2){
        res.push_back(nums[0]);
        return res;
      } 
      
      int val1,val2,count1=0,count2=0;
      
      //
      for(int i=0;i<n;i++){
        if(val1==nums[i])           count1++;
        else if(val2==nums[i])      count2++;
        else if(count1==0){
          val1=nums[i];
          count1=1;
        }
        else if(count2==0){
          val2=nums[i];
          count2=1;
        }
        else{
          count1--;count2--;
        } 
      }
      
      int temp1=0,temp2=0;
      //now count val1,val2
      for(int i=0;i<n;i++){
        if(val1==nums[i]) temp1++;
        if(val2==nums[i]) temp2++;
      }
      
      if(temp1>(n/3)) res.push_back(val1);
      if(temp2>(n/3)) res.push_back(val2);
      
      
      return res;
    }
};