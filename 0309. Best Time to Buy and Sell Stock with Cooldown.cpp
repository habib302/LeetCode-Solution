class Solution {
public:
    //dp[i][own][cooldown]
    int dp[5001][2][2];
    
    int helper(int i,bool own,bool cool,vector<int>& prices){
        //base case 1
        if(i==prices.size()) 
            return 0;
        
        //check in dp table
        if(dp[i][own][cool] != -1) 
            return dp[i][own][cool];
        
        //if own==false means we can buy or don't buy the stock
        //op1 = buy the stock
        //op2 = don't buy the stock
        if(!own){
            int op1 = (cool) ? 0 : (helper(i+1,true,false,prices)-prices[i]);
            int op2 =               helper(i+1,false,false,prices); 
            return dp[i][own][cool]=max(op1,op2);
        }
        //if own==true means we can sell or don't sell the stock
        //op1 = sell the stock
        //op2 = don't sell the stock
        else{
            int op1 = helper(i+1,false,true,prices) + prices[i];
            int op2 = helper(i+1,true,false,prices); 
            return dp[i][own][cool]=max(op1,op2);
        }
    }
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof dp);
        return helper(0,false,false,prices);
        
    }
};