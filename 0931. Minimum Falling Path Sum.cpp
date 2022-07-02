class Solution {
public:
    //memoization
    int dp[102][102];
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        //m==n
        int m=matrix.size();
        int res=INT_MAX;
        memset(dp,-1,sizeof dp);
        
        //base case
        //because square matrix
        if(m==1)
            return matrix[0][0];
        
        //different starting position
        for(int col=0;col<m;col++){
            // here row is always zero & column position is changing
            res = min(res, helper(0,col,matrix));
        }
        return res;
    }
    
    int helper(int i,int j,vector<vector<int>>& matrix){
        
        
        //base case 1 for row
        if(i==matrix.size()) 
            return 0;
        
        //base case 2 for column
        if(j<0 || j==matrix[0].size()) 
            return INT_MAX;
        
        //ai condition ta sobar upore dile kaj kore na
        if(dp[i][j] != -1) 
            return dp[i][j];
        
        //choice diagram
        int op1 = helper(i+1, j-1, matrix);
        
        int op2 = helper(i+1, j ,  matrix);
            
        int op3 = helper(i+1, j+1, matrix);
        
        return dp[i][j]=min({op1,op2,op3}) + matrix[i][j];
    }
};