// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        
        int start=1, end=n, res=-1;
        
        while(start <= end){
            
            int mid= start +(end-start)/2;
            
            if(isBadVersion(mid)==true){
                res = mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        
        return res;
    }
};

/*
suppose n=10, bad=3

boolisBadVersion(int val){
    
    if(val>=bad) return true;
    
    else return false;
}

*/