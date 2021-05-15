class Solution {
public:
    //memoization
    int dp[1002];
    bool divisorGame(int n) {
        memset(dp,-1,sizeof dp);
        return helper(n);
    }
    
    bool helper(int n){
        if(dp[n]!=-1) return dp[n];
        
        //base case 1
        if(n==1) return 0;
        
        bool res=false;
        
        //choice diagram
        for(int i=1;i<n;i++){
            if(n%i==0){
                res = res || !helper(n-i); 
                //using not means the optimal step used by bob 
            }
        }
        return dp[n]=res;
    }
};