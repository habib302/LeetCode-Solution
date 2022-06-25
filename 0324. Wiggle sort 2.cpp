class Solution {
public:
    void wiggleSort(vector<int>& nums) {
       
        int n=nums.size();
        vector<int> res(n,0);
        
        sort(nums.begin(),nums.end());
        int index=n-1;
        
        //first filling the odd position
        for(int i=1;i<n;i=i+2){
            res[i]=nums[index];
            index--;
        }
        
        //second filling the even position
        for(int i=0;i<n;i=i+2){
            res[i]=nums[index];
            index--;
        }
        
        //copy res to nums
        for(int i=0;i<n;i++){
            nums[i]=res[i];
        }
    }
};