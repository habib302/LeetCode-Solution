class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        vector<int> res;
        deque<int> dq;
        
        int left=0,right=0,n=nums.size();
        
        while(right < n){
            
            while(dq.size()>0 && dq.back() < nums[right]){
                dq.pop_back();
            }
            
            dq.push_back(nums[right]);
            
            //check length
            if(right-left+1 < k){
                right++;
            }
            else{
                res.push_back(dq.front());
                
                if(nums[left]==dq.front()){
                    dq.pop_front();
                }
                
                left++;
                right++;
            }
        }
        
        return res;
    }
};