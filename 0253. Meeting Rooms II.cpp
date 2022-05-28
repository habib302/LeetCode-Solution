class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        
        //base case
        if(intervals.size()==1) return 1;
        
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        sort(intervals.begin(), intervals.end());
        
        for(auto v: intervals){
            
            //check with minHeap top to start time
            if(minHeap.size()>0 && minHeap.top() <= v[0]){
                minHeap.pop();
            }
            
            //push the end time
            minHeap.push(v[1]);
        }
        
        return minHeap.size();
    }
};