//logic of sqrt of a number
class Solution {
public:
    bool isPerfectSquare(int num) {
        
        //base case
        if(num<3)
            return true;
        
        int start=1,end=num;
        
        while(start < end){
            
            long mid = start + (end-start)/2;
            
            if(mid*mid==num){
                return true;
            }
            else if(mid*mid < num){
                start = mid+1;
            }
            else{
                end = mid;
            }
        }
        
        return false;
    }
};