class Solution {
public:
    int trailingZeroes(int n) {
        
        int res=0,p=5;
        
        while( (n/p) > 0){
            res = res + (n/p);
            p = p*5;
        }
        
        return res;
    }
};