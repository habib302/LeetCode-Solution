class Solution {
public:
    vector<vector<int>> res;
    
    vector<vector<int>> combinationSum3(int k, int n) {
        
        //base case
        if(n<3) return res;
        
        vector<int> temp;
        vector<int> candidates {1,2,3,4,5,6,7,8,9};
        
        helper(0, n, k, temp,candidates);
        
        return res;
    }
    
    void helper(int index,int target, int k,vector<int> temp,vector<int> &candidates){
        
        //base case
        if(temp.size()==k && target==0){
            res.push_back(temp);
            return ;
        }
        
        if(temp.size()>k || target<0)
            return ;
        
        for(int i=index; i<candidates.size();i++){
            //add to temporary result
            temp.push_back(candidates[i]);
            
            //explore
            helper(i+1, target-candidates[i] , k, temp, candidates);
            
            //remove from temporary result
            temp.pop_back();
        }
    }
};