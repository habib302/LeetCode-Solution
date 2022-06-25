class Solution {
public:
    int dp[502][502];
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        memset(dp, -1, sizeof dp);
        return helper(0,0,nums1,nums2);
    }
    
    int helper(int i,int j,vector<int>& nums1, vector<int>& nums2){
        //base case
        if(i==nums1.size() && j==nums2.size()) return 0;
        if(i==nums1.size()) return 0;
        if(j==nums2.size()) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        //match
        if(nums1[i]==nums2[j]){
            return dp[i][j]=1+helper(i+1,j+1,nums1,nums2);
        }
        else{
            int op1 = helper(i+1, j  ,nums1,nums2);
            int op2 = helper(i  , j+1,nums1,nums2);
            return dp[i][j]=max(op1,op2);
        }
    }
};