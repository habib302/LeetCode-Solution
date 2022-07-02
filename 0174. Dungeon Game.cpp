class Solution {
public:
    int dp[202][202];
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m=dungeon.size(), n=dungeon[0].size();
        memset(dp,-1,sizeof dp);
        
        return helper(0,0,m,n,dungeon);
    }
    
    int helper(int i,int j,int m,int n,vector<vector<int>>& dungeon){
        //reached the bottom-right corner
        if(i==m-1 && j==n-1)
            return dungeon[i][j]<=0 ? abs(dungeon[i][j])+1 : 1;
        
		//boundary case
        if(i>=m || j>=n) 
            return INT_MAX;
        
        //check in dp table
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int op1 = helper(i+1, j  , m, n,dungeon);
        int op2 = helper(i , j+1, m, n,dungeon);
        
        int minHealth = min(op1,op2) - dungeon[i][j];
        
        return dp[i][j] = (minHealth<=0) ? 1 : minHealth;
    }
};