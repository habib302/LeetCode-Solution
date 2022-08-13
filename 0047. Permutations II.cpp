class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        helper(0, nums);
        
        return res;
    }
    
    void helper(int index, vector<int>& nums){
        
        //base case
        if(index==nums.size()){
            res.push_back(nums);
            return;
        }
        
        set<int> set;
        
        for(int i=index; i<nums.size();i++){
            
            //check duplicate
            if(set.count(nums[i])) 
				continue;
            set.insert(nums[i]);
            
            swap(nums[i], nums[index]);
            helper(index+1, nums);
            swap(nums[i], nums[index]);
        }
    }
}