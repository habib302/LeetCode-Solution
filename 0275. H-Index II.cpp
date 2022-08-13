class Solution {
public:
    int hIndex(vector<int>& citations) {
        
        int n=citations.size();
        int start=0, end=n-1;
        
        while(start <= end){
            
            int mid = start +(end-start)/2;
            int count = n-mid;
            
            if(citations[mid]==count){
                return count;
            }
            else if(citations[mid] > count){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        
        return n-start;
    }
};