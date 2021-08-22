class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        
        int m=nums.size(),maxKey=0;
        unordered_map<int,vector<int>> map;
        
        //map r+c as key & nums[r][c] as value
        for(int r=0;r<m;r++){
            for(int c=0;c<nums[r].size();c++){
                map[r+c].push_back(nums[r][c]);
                maxKey=max(maxKey,r+c);
            }
        }
        
        vector<int> res;
        
        //traverse the map
        for(int i=0;i<=maxKey;i++){
            
            //push in reverse
            for(auto x=map[i].rbegin(); x != map[i].rend(); x++){
                res.push_back(*x);
            }
        }
        
        return res;
    }
};