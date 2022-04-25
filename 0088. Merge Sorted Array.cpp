class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int i=nums1.size()-n-1, j=n-1, k=nums1.size()-1;
        
        //base case
        if(n==0) return;
        if(m==0){
            for(int i=0;i<n;i++){
                nums1[i]=nums2[i];
            }
            return ;
        }
        
        cout<<i<<" "<<j<<" "<<k<<endl;
        
        while(i>=0 && j>=0){
            if(nums1[i] <= nums2[j]){
                nums1[k]=nums2[j];
                k--;
                j--;
            }
            else{
                nums1[k]=nums1[i];
                k--;
                i--;
            }
        }
        
        //check i==-1 and j != -1
        if(i==-1){
            while(j>=0){
                nums1[k]=nums2[j];
                k--;
                j--;
            }
            return ;
        }
        
        //check i !=- 1 and j == -1
        if(j==-1){
            while(i>=0){
                nums1[k]=nums1[i];
                k--;
                i--;
            }
        }
        
        return ;
    }
};