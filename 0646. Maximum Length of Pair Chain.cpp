class Solution {
public:
    static bool cmp(vector<int> v1, vector<int> v2){
        //[6,4] [6,7]
        if(v1[0]==v2[0]){
            return v1[1] < v2[1];
        }
        else return v1[0] < v2[0];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        
        //base case
        if(n==1) return 1;
        
        sort(pairs.begin(), pairs.end(),cmp);
        vector<int> dp(n,1);
        
        int maxLength=1;
        
        //same as LIS
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(pairs[j][1] < pairs[i][0] ){
                    
                    if(dp[i]<dp[j]+1){
                        dp[i] = dp[j]+1;
                    }
                }
            }
            maxLength = max(maxLength,dp[i]);
        }
        
        return maxLength;
    }
};