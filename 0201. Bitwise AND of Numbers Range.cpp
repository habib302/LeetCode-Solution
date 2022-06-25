class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        
        int count=0;
        
        while(left != right){
            
            //left & right ke 1bit right shift korbo
            left = left>>1;
            right = right>>1;
            
            count++;
        }
        
        return left<<count;
    }
};