class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        vector<int> temp;
        sort(nums.begin(),nums.end());
        
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
        
        //check duplicate
        while(index+1 < nums.size() && nums[index]==nums[index+1]){
            index++;
        }
        
        //not-include ith-index
        temp.pop_back();
        helper(index+1, temp, nums);
    }
};