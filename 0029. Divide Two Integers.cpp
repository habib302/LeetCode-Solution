class Solution {
public:
//INT_MIN is -2147483648.
//INT_MAX is +2147483647.
// thats why i need to use long
//brute force
    int divide(int dividend, int divisor) {
        
        //base case
        if(divisor==1) return dividend;
        if(dividend==INT_MIN && divisor==-1) return INT_MAX;
        
        int count=0;
        int sign = (dividend<0) xor (divisor<0) ? -1 :1;
        
        long dividend2 = abs(dividend) ; 
		long divisor2 = abs(divisor);
        
        while( (dividend2 - divisor2) >=0 ){
            count++;
            dividend2 = dividend2 - divisor2;
        }
        
        return sign*count;
    }
};