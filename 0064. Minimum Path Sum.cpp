class Solution {
public:
    int dp[202][202];
    
    int minPathSum(vector<vector<int>>& grid) {
        
        memset(dp, -1, sizeof dp);
        int m=grid.size(), n=grid[0].size();
        return helper(m-1,n-1,grid); 
    }
    
    int helper(int i,int j, vector<vector<int>>& grid){
        //base case
        if(i==0 && j==0) 
			return grid[i][j];
        if(i<0 || j<0) 
			return INT_MAX;
        
        if(dp[i][j] != -1) 
			return dp[i][j];
        
        int op1=helper(i-1,j,grid);
        int op2=helper(i,j-1,grid);
        
        return dp[i][j]= min(op1,op2) + grid[i][j];
    }
};