class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int n=nums.size();
        
        //base case
        if(n==1){
            return ;
        }
        
        int idx1=-1,idx2=-1;
        
        //find idx1 from end
        for(int i=n-1;i>0;i--){
            if(nums[i-1]<nums[i]){
                idx1=i-1;
                break;
            }
        }
        
        //check 5 4 3 2 1
        if(idx1 == -1){
            reverse(nums.begin(),nums.end());
            return ;
        }
        
        
        //find idx2 from end
        for(int i=n-1;i>=0;i--){
            
            if( nums[i] > nums[idx1]){
                idx2=i;
                break;
            }
            
        }
        
        swap(nums[idx1], nums[idx2]);
        
        reverse(nums.begin()+idx1+1, nums.end());
        
        return;
    }
};