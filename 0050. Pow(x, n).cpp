//brute force
class Solution {
public:
    double myPow(double x, int n) {
        
        //base case
        if(n==0) return 1.0;
        if(n==1) return x;
        if(n<0) return myPow(1/x, n*(-1));
        
        double res=1.0;
        
        for(int i=0;i<n;i++){
            res = res * x;
        }
        
        return res;
    }
};

-----------------------------------------------
class Solution {
public:
    double myPow(double x, int n) {
        return helper(x,n);
    }
    
    double helper(double x, long n){
        //base case
        if(n==0) return 1.0;
        if(n==1) return x;
        if(n<0) return helper(1/x, abs(n));
        
        double res=helper(x*x, n/2);
        
        //n odd hole arekbar multiply korbo
        if(n%2==1) res = res * x;
        return res;
    }
};