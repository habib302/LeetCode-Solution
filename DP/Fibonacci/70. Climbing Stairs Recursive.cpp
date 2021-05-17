class Solution {
public:
    //recursion
    int climbStairs(int n) {
        return helper(n);
    }
    
    int helper(int n){
        //base case 1
        if(n<0) return 0;
        
        //base case 2
        if(n==0) return 1;
        
        //choice diagram
        int op1 = helper(n-1);
        int op2 = helper(n-2);
        
        return op1+op2;
    }
};