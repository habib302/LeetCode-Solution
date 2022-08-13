class Solution {
public:
    int dp[46];
    int climbStairs(int n) {
        memset(dp,-1,sizeof dp);
        return helper(n);
        
    }
    
    int helper(int n){
        
        //base case 1
        if(n==1) 
			return 1;
        if(n==2) 
			return 2;
        if(n==3) 
			return 3;
		
		//check in dp table
		if(dp[n]!=-1) 
			return dp[n];
        
        //choice diagram
        int op1 = helper(n-1);
        int op2 = helper(n-2);
        
        return dp[n]=op1+op2;
    }
};