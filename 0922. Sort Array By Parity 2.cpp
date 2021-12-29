class Solution {
//method 1: using two variable
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        
      int n=nums.size(),even=0,odd=1;
      
      //step 1:traverse from 0-n
      while(even<n && odd<n){
        
        //step 2: find odd number in even position
        while(even<n){ 
          if(nums[even]%2==0){
            even += 2;
          }else{
            break;
          }
        }
        
        //step 3: find even number in odd position
        while(odd<n){ 
          if(nums[odd]%2==1){
            odd += 2;
          }else{
            break;
          }
        }
        
        //step4: check even & odd in range and swap... then increase
        if(even<n && odd<n){
          swap(nums[even],nums[odd]);
        }

      }
      
      return nums;
    }
};