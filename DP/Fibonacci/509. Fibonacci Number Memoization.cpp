class Solution {
public:
    //memoization
    int dp[32];
    int fib(int n) {
        memset(dp,-1,sizeof dp);;
       return helper(n); 
    }
    
    int helper(int n){
        if(dp[n]!=-1) return dp[n];
        
        //base case 1
        if(n==0) return 0;
        
        //base case 2
        if(n==1) return 1;
        
        //choice diagram
        return dp[n]=helper(n-1)+helper(n-2);
    }
};