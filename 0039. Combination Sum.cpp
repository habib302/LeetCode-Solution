class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<int> temp;
        
        //sort kore nibo na hole duplicate ans asbe
        sort(candidates.begin(), candidates.end());
        
        helper(0, target,temp,candidates);
            
        return res;
    }
    
    void helper(int index, int target, vector<int> temp, vector<int>& candidates){
        
        //base case
        if(target==0){
            res.push_back(temp);
            return ;
        }
        
        if(target<0)
            return;
        
        for(int i=index;i<candidates.size();i++){
            //add to temporary result
            temp.push_back(candidates[i]);
            
            //explore
            helper(i, target-candidates[i],temp,candidates);
            
            //remove from temporary result
            temp.pop_back();
        }
    }
};