class Solution {
public:
    int getSum(int a, int b) {
        if(a==0) return b;
        if(b==0) return a;
        
        //unsigned int for handle negative no
        unsigned int carry=0;
        
        while(b!=0){
            carry = a & b;     //find the carry
            a     = a ^ b;     //xor of a,b
            b     = carry <<1; //left shift the carry 1bit
        }
        
        return a;
    }
};