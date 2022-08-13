class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int n=nums.size(),left=0,right,sum=0;
        right=n-1;
        
        vector<int> res;
        
        while(left < right){
            sum = nums[left]+nums[right];
            
            if(sum==target){
                res.push_back(left);
                res.push_back(right);
                break;
            }
            else if(sum < target){
                left++;
            }
            else{
                right--;
            }
        }
        
        //add 1 to index 0 & 1, because 1 based index bolche
        res[0]=res[0]+1;
        res[1]=res[1]+1;
        
        return res;
    }
};