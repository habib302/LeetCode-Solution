class Solution {
public:
    int dp[2001][2001];
    bool isOneEditDistance(string &s, string &t) {
        // write your code here
        memset(dp,-1,sizeof dp);
        int distance=helper(0,0,s,t);
        if(distance==1) return true;
        else return false;
    }

    int helper(int i,int j,string &s1, string &s2){
        if(dp[i][j]!=-1) return dp[i][j];

        //base case 1
        if(i==s1.size() && j==s2.size()) return 0;

        //base case 2
        if(i==s1.size()) return s2.size()-j;

        //base case 3
        if(j==s2.size()) return s1.size()-i;

        //choice diagram
        if(s1[i]==s2[j]){
            return dp[i][j]=helper(i+1,j+1,s1,s2);
        }else{
            int op1 = 1 + helper(i,j+1,s1,s2);    //insert
            int op2 = 1 + helper(i+1,j,s1,s2);    //delete
            int op3 = 1 + helper(i+1,j+1,s1,s2);  //replace

            return dp[i][j]=min(op1,min(op2,op3));
        }
    }
};