//method 1: using 2 loop
//method 2: using map
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> res;
        unordered_map<int,int> map;
        
        int n=nums.size(),temp=0;
        
        for(int i=0;i<n;i++){
            temp = target-nums[i];
            
            if(map.find(temp) != map.end()){
                res.push_back(map[temp]);  //1st index
                res.push_back(i);          //2nd index
                break;
            }
            else map.insert({nums[i],i});
        }
        
        return res;
    }
};