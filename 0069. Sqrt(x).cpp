class Solution {
public:
    int mySqrt(int x) {
        
        //base case
        if(x<2)
            return x;
        
        int start=0, end=x;
        
        while(start < end){
            
            long mid = start + (end-start)/2;
            
            if(mid*mid==x){
                return mid;
            }
            else if(mid*mid < x){
                start = mid+1;
            }
            else{
                end = mid;
            }
        }
        
        return start-1;
    }
};