class Solution {
public:
    //memoization
    int dp[202][202];
    int minFallingPathSum(vector<vector<int>>& arr) {
        
        //m==n
        int m=arr.size();
        int res=INT_MAX;
        memset(dp,-1,sizeof dp);
        
        //base case
        //because square matrix
        if(m==1)
            return arr[0][0];
        
        //different starting position
        for(int col=0;col<m;col++){
            // here row is always zero & column position is changing
            res = min(res, helper(0,col,arr));
        }
        return res;
        
    }
    
    int helper(int i,int j,vector<vector<int>>& matrix){
        
        //base case 1 for row
        if(i==matrix.size()) 
            return 0;
        
        //ai condition ta sobar upore dile kaj kore na
        if(dp[i][j] != -1) 
            return dp[i][j];
        
        int temp=INT_MAX;
        //choice diagram
        
        for(int j1=0; j1<matrix[0].size(); j1++){
            
            //check j & j1 are in different column
            if(j != j1){
                temp = min( temp, helper(i+1, j1, matrix) + matrix[i][j]);
            }
        }
        
        return dp[i][j]=temp;
    }
};