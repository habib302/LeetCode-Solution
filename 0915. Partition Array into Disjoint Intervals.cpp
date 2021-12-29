//method 1: using minRight array
class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
      int n=nums.size();
      
      if(n==2) return 1;
      vector<int> minRight(n,0);
      
      //find minRight from end
      //base case
      minRight[n-1]=nums[n-1];
      
      for(int i=n-2;i>=0;i--){
        minRight[i]=min(nums[i], minRight[i+1]);
      }
      
      //compare and check with minRight[i] with maxLeft
      //base case
      int maxLeft=nums[0];
      
      for(int i=1;i<n;i++){
        maxLeft=max(maxLeft,nums[i-1]);
        if(maxLeft <= minRight[i]){
          return i;
        }
      }
      
      return -1;
    }
};