//using sort
//TC= O(nlogn)   SC= O(n) 

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n=nums.size();
        
        sort(nums.begin(),nums.end());
        vector<int> res(n,0);
        
        int j=n-1;
        //feeling odd position
        for(int i=1;i<n;i=i+2){
            res[i]=nums[j];
            j--;
        }
        
        //feeling even position
        for(int i=0;i<n;i=i+2){
            res[i]=nums[j];
            j--;
        }
        
        //copy res to nums
        for(int i=0;i<n;i++){
            nums[i]=res[i];
        }
    }
};