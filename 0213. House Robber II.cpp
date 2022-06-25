class Solution {
public:
    int dp1[102];
    int dp2[102];
    
    int rob(vector<int>& nums) {
        
        int n=nums.size();
        
        //extra base case need to handle
        if(n==1) return nums[0];
        if(n==2) return max(nums[0], nums[1]);
        
        //zero based index
        n--;
        
        memset(dp1, -1, sizeof dp1);
        memset(dp2, -1, sizeof dp2);
        
        int maxMoney1 = helper1(n-1,nums);
        int maxMoney2 = helper2(n,nums);
        
        return max(maxMoney1,maxMoney2);
    }
    
    //from 0--(n-1)
    int helper1(int n,vector<int>& nums){
        //base case
        if(n<0) return 0;
        
        if(dp1[n]!=-1) return dp1[n];
        
        int op1=helper1(n-2, nums) + nums[n];
        int op2=helper1(n-1, nums) ;
        
        return dp1[n]=max(op1,op2);
    }
    
    //from 1---(n)
    int helper2(int n,vector<int>& nums){
        //base case
        if(n<1) return 0;
        
        if(dp2[n]!=-1) return dp2[n];
        
        int op1=helper2(n-2, nums) + nums[n];
        int op2=helper2(n-1, nums) ;
        
        return dp2[n]=max(op1,op2);
    }
};