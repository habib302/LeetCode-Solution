class Solution {
public:
    //same as LCS memoization
    int dp[102][10002];
    bool isSubsequence(string s, string t) {
        int n=s.size(),m=t.size();
        
        memset(dp,-1,sizeof dp);
        int LCS=helper(0,0,s,t);
        
        if(LCS==n){
            return true;
        }else return false;
    }
    
    //LCS Memoization
    int helper(int i,int j,string& s1, string& s2){
        if(dp[i][j] != -1 ) return dp[i][j];
        
        //base case 1
        if(i==s1.size()) return 0;
        
        //base case 2
        if(j==s2.size()) return 0;
        
        
        //choice diagram
        if(s1[i]==s2[j]){
            return dp[i][j]= 1 + helper(i+1,j+1,s1,s2);
        }else{
            int op1 = helper(i+1,j,s1,s2);
            int op2 = helper(i,j+1,s1,s2);
            
            return dp[i][j]=max(op1,op2);
        }
        
    }
    
};