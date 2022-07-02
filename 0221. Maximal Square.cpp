class Solution {
public:
    int dp[302][302];
    int maximalSquare(vector<vector<char>>& matrix) {
        
        int m=matrix.size(),n=matrix[0].size();
        memset(dp,-1,sizeof dp);
        int res=0;
        
        //two loop for starting different position
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                
                if(matrix[i][j]=='1'){
                    res = max(res, helper( i, j, m, n, matrix) );
                } 
            }
        }
        return res*res;
    }
    
    //forward recursion
    int helper(int i, int j, int m, int n, vector<vector<char>>& matrix){
        
        //base case
        if(i>=m || j>=n) return 0;
        if(matrix[i][j]=='0') return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        //choice diagram
        int op1 = helper( i+1, j  , m, n, matrix);
        int op2 = helper( i  , j+1, m, n, matrix);
        int op3 = helper( i+1, j+1, m, n, matrix);
        
        return dp[i][j] = min({op1,op2,op3})+1;
    }
};