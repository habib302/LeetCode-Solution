class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int m=nums1.size();
        int n=nums2.size();
        
        //assure that nums1.size() < nums2.size()
        if(m>n){
            return findMedianSortedArrays(nums2,nums1);
        }
        
        int start=0,end=m;
        
        while( start <= end){
            int mid1= (start+end)/2;
            int mid2= (m+n+1)/2 - mid1;
            
            int max1 = (mid1==0) ? INT_MIN : nums1[mid1-1];
            int min1 = (mid1==m) ? INT_MAX : nums1[mid1];
            
            int max2 = (mid2==0) ? INT_MIN : nums2[mid2-1];
            int min2 = (mid2==n) ? INT_MAX : nums2[mid2];
            
            // max1  min1
            // max2  min2
            
            if((max1 <= min2) && (max2 <= min1)){
                if((m+n)%2==0){
                    return (max(max1,max2)+min(min1,min2))/2.0;
                }
                
                else{
                    return max(max1,max2)*1.0;
                }
            }
            else if(max1 > min2){
                end = mid1-1; 
            }
            else{
                start = mid1+1;
            }
        }
        
        return 0.0;
    }
};