class Solution {
public:
    vector<vector<int>> res;
    
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<int> temp;
        
        helper(0,temp,nums);
        
        return res;
    }
    
    void helper(int index, vector<int> temp, vector<int> nums){
        
        //base case
        if(index==nums.size()){
            res.push_back(temp);
            return ;
        }
        
        //include ith-index 
        temp.push_back(nums[index]);
        helper(index+1, temp, nums);
        
        //not-include ith-index
        temp.pop_back();
        helper(index+1, temp, nums);
    }
};