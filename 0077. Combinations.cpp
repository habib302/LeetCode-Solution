class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combine(int n, int k) {
        
        vector<int> temp,nums;
        
        for(int i=1;i<=n;i++){
            nums.push_back(i);
        }
        
        helper(0, k, temp, nums);
        
        return res;
    }
    
    void helper(int index,int k,vector<int> temp, vector<int> nums){
        
        //base case
        if(temp.size()==k){
            res.push_back(temp);
            return;
        }
        
        for(int i=index;i<nums.size();i++){
            temp.push_back(nums[i]);
            helper(i+1,k,temp,nums);
            temp.pop_back();
        }
    }
};