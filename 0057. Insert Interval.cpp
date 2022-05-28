class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        vector<vector<int>> res;
        
        int x1,y1,x2,y2;
        
        for(int i=0;i<intervals.size();i++){
            
            x1=intervals[i][0];
            y1=intervals[i][1];
            
            x2=newInterval[0];
            y2=newInterval[1];
            
            
            //case 1:
            if(y1 < x2){
                res.push_back({x1,y1});
            }
            else if(y2 < x1){
                res.push_back({x2,y2});
                
                newInterval[0] = x1;
                newInterval[1] = y1;
            }
            else{
                newInterval[0] = min(x1,x2);
                newInterval[1] = max(y1,y2);
            }
        }
        
        res.push_back(newInterval);
        
        return res;
    }
};