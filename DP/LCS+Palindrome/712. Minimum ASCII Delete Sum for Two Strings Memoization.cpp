class Solution {
public:
    //memoization
    int dp[1002][1002];
    int minimumDeleteSum(string s1, string s2) {
        memset(dp,-1,sizeof dp);
        return helper(0,0,s1,s2);
    }
    
    int helper(int i,int j,string& s1, string& s2){
        if(dp[i][j] != -1) return dp[i][j];
        
        //base case 1
        if(i==s1.size() && j==s2.size()) return 0;
        
        //base case 2
        if(i==s1.size()){
            return int(s2[j])+helper(i,j+1,s1,s2);
        }
        
        //base case 3
        if(j==s2.size()){
            return int(s1[i])+helper(i+1,j,s1,s2);
        }
        
        //choice diagram
        if(s1[i]==s2[j]){
            return dp[i][j]=helper(i+1,j+1,s1,s2);
        }else{
            int op1 =  int(s1[i])+helper(i+1,j,s1,s2);
            int op2 =  int(s2[j])+helper(i,j+1,s1,s2);
            
            return dp[i][j]=min(op1,op2);
        }
    }
};