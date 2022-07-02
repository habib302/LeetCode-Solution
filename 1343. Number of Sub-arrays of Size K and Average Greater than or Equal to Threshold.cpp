class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        
        int n=arr.size(),left=0,right=0,count=0,sum=0;
        
        for(right=0; right<n; right++){
            
            sum = sum + arr[right];
            
            if(right >= k-1){
                int avg = sum/k;
                
                //check if avg greater than threshold 
                //then update count;
                if(avg>=threshold){
                    count++;
                }
                
                //relase from sum
                //increment left by 1
                sum = sum - arr[left];
                left++;
            }
        }
        
        return count;
    }
};