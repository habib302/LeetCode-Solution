class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        
        if(n<2) 
			return 0;
        
        int maxProfit=0;
        
        for(int i=1;i<n;i++){
            if(prices[i-1] < prices[i]){
                maxProfit = maxProfit + (prices[i] - prices[i-1]);
            }
        }
        
        return maxProfit;
    }
};