class Solution {
public:
    //dp[i][own]
    int dp[50001][2];
    
    int helper(int i,bool own,int fee,vector<int>& prices){
        
        //base case 1
        if(i==prices.size()) 
            return 0;
        
        //check in dp table
        if(dp[i][own] != -1) 
            return dp[i][own];
        
        //if own==false means we can buy or don't buy the stock
        //op1 = buy the stock
        //op2 = don't buy the stock
        if(!own){
            int op1=  helper(i+1,true,fee,prices) - (prices[i]+fee);
            int op2=  helper(i+1,false,fee,prices);
            return dp[i][own]=max(op1,op2);
            
        }
        //if own==true means we can sell or don't sell the stock
        //op1 = sell the stock
        //op2 = don't sell the stock
        else{
            int op1=  helper(i+1,false,fee,prices) + prices[i];
            int op2=  helper(i+1,true,fee,prices);
            return dp[i][own]=max(op1,op2);
            
        }
    }
    
    int maxProfit(vector<int>& prices, int fee) {
        memset(dp,-1,sizeof(dp));
        return helper(0,false,fee,prices);
    }
};