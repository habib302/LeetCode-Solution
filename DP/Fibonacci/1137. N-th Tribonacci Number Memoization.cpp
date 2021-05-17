class Solution {
public:
    //memoization
    int dp[39];
    int tribonacci(int n) {
        memset(dp,-1,sizeof dp);
        return helper(n);
    }
    
    int helper(int n){
        if(dp[n] != -1) return dp[n];
        
        //base case 1
        if(n==0) return 0;
        
        //base case 2
        if(n==1) return 1;
        
        //base case 3
        if(n==2) return 1;
        
         //choice diagram
        int op1 = helper(n-1);
        int op2 = helper(n-2);
        int op3 = helper(n-3);
        
        return dp[n] = op1+op2+op3;
    }
};