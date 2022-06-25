class Solution {
public:
    vector<string> res;
    
    vector<string> generateParenthesis(int n) {
        
        helper(0, 0, n, "");
        
        return res;
    }
    
    void helper(int open, int close, int n, string temp){
        
        //base case
        if(temp.size()==n*2){
            res.push_back(temp);
            return;
        }
        
        if(open < n ){
            helper( open+1, close, n, temp+"(" );
        }
        
        if(open > close ){
            helper( open, close+1, n, temp+")" );
        }
    }
};