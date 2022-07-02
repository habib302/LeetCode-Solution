class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        vector<int> res;
        deque<int> dq;
        
        int left=0,right=0,n=nums.size();
        
        for(right=0; right < n;right++){
            
            //step 1:remove from dq.back until nums[right] greater
            while(dq.size()>0 && dq.back() < nums[right]){
                dq.pop_back();
            }
            
            //step 2: push nums[right] to deque
            dq.push_back(nums[right]);
            
            // for (auto it = dq.begin(); it != dq.end(); ++it)
            //     cout << ' ' << *it;
            // cout<<endl;
            
            //we found the window size
            if(right >= k-1){
                
                //update the result
                res.push_back(dq.front());
                
                //check if nums[left]==dq.front
                //then remove from deque
                if(nums[left]==dq.front()){
                    dq.pop_front();
                }
                
                //increment left by 1
                left++;
            }
        }
        
        return res;
    }
};