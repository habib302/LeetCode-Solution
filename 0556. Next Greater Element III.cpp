class Solution {
public:
    int nextGreaterElement(int n) {
      //base case
      if(n<12) return -1;
      
      string nums=to_string(n);
      int len=nums.size(),index;
      
      //start from len-2 and check
      for(index=len-2;index>=0;index--){
        if(nums[index]<nums[index+1]){
          break;
        }
      }
      
      //jodi index -1 hoy orthat 54321 kono decreasing order nai
      if(index==-1) return -1;
      
      //swap the element 
      for(int i=len-1; i>index;i--){
        if(nums[index]<nums[i]){
          swap(nums[index],nums[i]);
          break;
        }
      }
      
      //reverse index+1 to end
      reverse(nums.begin() + index + 1, nums.end());
      
      return stol(nums) > INT_MAX ? -1 : stoi(nums);
    }
};