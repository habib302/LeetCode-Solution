// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        
        //bad is always between the range
        //so don't need to check base case
        
        int start=1,end=n;
        
        //lower bound for binary search
        while(start < end){
            
            int mid = start + (end-start)/2;
            
            if(isBadVersion(mid)){
                end = mid;
            }
            else{
                start = mid+1;
            }
        }
        
        return start;
    }
};

/*
suppose n=10, bad=3

boolisBadVersion(int val){
    
    if(val>=bad) return true;
    
    else return false;
}

*/