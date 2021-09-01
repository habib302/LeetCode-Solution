//using map
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        // nums[i], index
        unordered_map<int,int> map;
        
        for(int i=0;i<nums.size();i++){
            
            //check in map
            if( map.count(nums[i]) ){
                int j=map[nums[i]];
                
                if( abs(i-j) <=k ){
                    return true;
                }
            }
            
            //push in map
            map[nums[i]]=i;
        }
        
        return false;
    }
};