class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        
        int maxSplit=0;
        
        //prefixSum -> split count
        unordered_map<int,int> map;
        
        int row=wall.size(),prefixSum=0;
        
        for(int i=0;i<row;i++){
            prefixSum=0;
            for(int j=0; j<wall[i].size()-1;j++){
                prefixSum = prefixSum + wall[i][j];
                
                map[prefixSum]++;
                
                maxSplit = max(maxSplit, map[prefixSum]);
            }
        }
        
        return row-maxSplit;
    }
};