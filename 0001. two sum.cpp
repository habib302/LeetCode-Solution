//method 1: using 2 loop
//method 2: using map
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> res;
        unordered_map<int,int> mp;
        
        int n=nums.size(),temp=0;
        
        for(int i=0;i<n;i++){
            temp = target-nums[i];
            
            if(mp.count(temp)){
                res.push_back(mp[temp]);  //1st index
                res.push_back(i);          //2nd index
                break;
            }
            else mp.insert({nums[i],i});
        }
        
        return res;
    }
};