class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        
        int x1,y1,x2,y2;

        x2=intervals[0][0];
        y2=intervals[0][1];
        
                                                             
        for(int i=0;i<intervals.size();i++){
            
            //first get the x1,y1
            x1=intervals[i][0];
            y1=intervals[i][1];
            
            //case 1:(x1,y1) < (x2,y2)
            if(y1 < x2){
                res.push_back({x1,y1});
            }
            //case 2:(x1,y1) > (x2,y2)
            else if(x1 > y2){
                res.push_back({x2,y2});
                
                x2=x1;
                y2=y1;
            }
            //case 3: overlap
            else{
                x2 = min(x1,x2);
                y2 = max(y1,y2);
            }
        }
        
        res.push_back({x2,y2});
        
        return res;
    }
};