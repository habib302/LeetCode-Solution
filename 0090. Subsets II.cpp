class Solution {
public:
    
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        vector<int> temp;
        
        sort(nums.begin(),nums.end());
        
        helper(0,temp,nums);
        
        return res;
    }
    
    //backtracking
    void helper(int index,vector<int> temp, vector<int>& nums){
        //base case
        res.push_back(temp);
        
        for(int i=index;i<nums.size();i++){
            //duplicate
            if(i>index && nums[i]==nums[i-1]){
                continue;
            }
            
            temp.push_back(nums[i]);
            helper(i+1,temp,nums);
            temp.pop_back();
        }
    }
};