class Solution {
public:
    int dp[201][201];
    int minimumTotal(vector<vector<int>>& triangle) {
        memset(dp,-1,sizeof dp);
        return helper(0,0,triangle);
    }
    
    int helper(int i,int j,vector<vector<int>>& triangle){
        
        //boundary case
        if(i==triangle.size() || j==triangle[i].size()) 
            return 0;
        
        if(dp[i][j] != -1) 
            return dp[i][j];
        
        int op1 = helper(i+1, j  , triangle);
        int op2 = helper(i+1, j+1, triangle);
        
        return dp[i][j] = min(op1,op2) + triangle[i][j];
    }
};