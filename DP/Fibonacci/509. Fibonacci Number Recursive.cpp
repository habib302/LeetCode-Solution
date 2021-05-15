class Solution {
public:
    int fib(int n) {
       return helper(n); 
    }
    
    int helper(int n){
        //base case 1
        if(n==0) return 0;
        
        //base case 2
        if(n==1) return 1;
        
        //choice diagram
        return helper(n-1)+helper(n-2);
    }
};