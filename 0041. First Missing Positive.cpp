//using sort
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        set<int> set;
        int n=nums.size(),count=0;
        
        for(int i=0;i<n;i++){
            if(nums[i]<1){
                continue;
            }else{
                set.insert(nums[i]);
                count++;
            }
        }
        
        int res=1;
        while(count--){
            if(set.count(res)){
                res++;
            }else{
                return res;
            }
        }
        
        return res;
    }
};