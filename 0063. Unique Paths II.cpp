class Solution {
public:
    int dp[102][102];
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        memset(dp, -1, sizeof dp);
        int m=obstacleGrid.size(), n=obstacleGrid[0].size();
        return helper(m-1,n-1,obstacleGrid);
    }
    
    int helper(int i,int j, vector<vector<int>>& obstacleGrid){
        //base case
        if(i==0 && j==0 && obstacleGrid[i][j]!=1) 
			return 1;
        if(i<0 || j<0) 
			return 0;
        if(obstacleGrid[i][j]==1) 
			return 0;
        
        if(dp[i][j] != -1) 
			return dp[i][j];
        
        int op1=helper(i-1,j,obstacleGrid);
        int op2=helper(i,j-1,obstacleGrid);
        
        return dp[i][j]=op1+op2;
    }
};