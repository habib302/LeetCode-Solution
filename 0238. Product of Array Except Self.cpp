//method 1: using left array & right array
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
      int n=nums.size();
      vector<int> res(n,0),left(n,0),right(n,0) ;
      
      
      //base case
      //n er value min 2 hobe
      if(n==2){
        res[0]=nums[1];
        res[1]=nums[0];
        return res;
      }
      
      //create the left array
      //base case
      left[0]=nums[0];
      for(int i=1;i<n;i++){
        left[i] = nums[i]*left[i-1];
      }
      
      //create the right array
      //base case
      right[n-1]=nums[n-1];
      for(int i=n-2;i>=0;i--){
        right[i] = nums[i]*right[i+1];
      }
      
      //create the res
      res[0]=right[1];
      res[n-1]=left[n-2];
      
      for(int i=1;i<n-1;i++){
        res[i] = left[i-1]*right[i+1];
      }
      
      return res;
    }
};


//method 1: using only left array
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
      int n=nums.size();
      vector<int> left(n,0);
      
      
      //base case
      //n er value min 2 hobe
      if(n==2){
        left[0]=nums[1];
        left[1]=nums[0];
        return left;
      }
      
      //create the left array
      //base case
      left[0]=nums[0];
      for(int i=1;i<n;i++){
        left[i] = nums[i]*left[i-1];
      }
      
      int prod=nums[n-1];
      
      //left[n-1] base case
      left[n-1]=left[n-2];
      
      for(int i=n-2;i>0;i--){
        left[i]=left[i-1]*prod;
        prod = prod * nums[i];
      }
      
      //left[0] base case
      left[0]=prod;
      
      return left;
    }
};