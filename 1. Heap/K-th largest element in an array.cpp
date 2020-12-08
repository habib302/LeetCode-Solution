class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
      
      //initialize min-heap
      priority_queue<int, vector<int>, greater<int>> pq;
      
      int n=nums.size();
      
      //step1: push the element to heap
      //step2: check heap size & pop
      
      for(int i=0;i<n;i++){
        
        pq.push(nums[i]);
        
        if(pq.size()>k){
          pq.pop();
        }
        
      }
      
      //return an integer
      return pq.top();
    }
};