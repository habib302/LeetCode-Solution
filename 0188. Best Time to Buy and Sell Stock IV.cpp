class Solution {
public:
    //memoization
    int dp[1002][2][102];
    int helper(int i,bool own,int c,int k,vector<int>& prices){
        //base case 1
        if(i==prices.size() || c>k) 
            return 0;
        
        //check in dp table
        if(dp[i][own][c] != -1) 
            return dp[i][own][c];
        
        //if own==false means we can buy or don't buy the stock
        //op1 = buy the stock
        //op2 = don't buy the stock
        if(!own){
            int op1 = helper(i+1, true, c+1, k, prices) - prices[i];
            int op2 = helper(i+1, false, c, k,prices);
            return dp[i][own][c]=max(op1,op2);
        }
        //if own==true means we can sell or don't sell the stock
        //op1 = sell the stock
        //op2 = don't sell the stock
        else{
            int op1 = helper(i+1, false, c, k, prices) + prices[i];
            int op2 = helper(i+1, true, c, k, prices);
            return dp[i][own][c]=max(op1,op2);
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        memset(dp,-1,sizeof dp);
        return helper(0,false,0,k,prices);
    }
};