class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        
        if(intervals.size()<2) return true;
        
        sort(intervals.begin(), intervals.end());
        
        for(int i=1;i<intervals.size();i++){
            if(intervals[i-1][1] >  intervals[i][0])
                return false;
        }
        
        return true;
    }
};