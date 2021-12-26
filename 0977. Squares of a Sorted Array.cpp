//method 1: using sort
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        
        for(int i=0;i<n;i++){
            nums[i] = nums[i]* nums[i];
        }
        
        sort(nums.begin(),nums.end());
        return nums;
    }
};

//method 2: using extra space 
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size(),left=0,right,j;
        right=n-1,j=n-1;
        vector<int> res(n,0);
        
        // equal for -5 -3 -2 -1
        while(left <= right){
            if( abs(nums[left]) < abs(nums[right]) ){
                res[j]=nums[right]*nums[right];
                right--;
            }
            else{
                res[j]=nums[left]*nums[left];
                left++;
            }
            
            j--;
        }
        
        return res;
    }
};