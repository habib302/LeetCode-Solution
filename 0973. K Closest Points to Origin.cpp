class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        vector<vector<int>> res;
        
        //distance, x2,y2
        priority_queue< pair<int,pair<int,int>>> maxHeap;
        
        int x1=0,y1=0,x2,y2, dist=0;
        
        for(auto point:points){
            
            x2 = point[0];
            y2 = point[1]; 
            
            dist = pow((-x2),2) + pow((-y2),2);
            
            //cout<<dist<<" ";
            
            maxHeap.push({dist, {x2,y2}});
            
            if(maxHeap.size() > k){
                maxHeap.pop();
            }
        }
        
        while(maxHeap.size()>0){
            
            int a=maxHeap.top().second.first;
            int b=maxHeap.top().second.second;
            
            vector<int> temp;
            temp.push_back(a);
            temp.push_back(b);
            
            res.push_back(temp);
            
            maxHeap.pop();
            
            cout<<a<<" "<<b<<endl;
        }
        
        return res;
    }
};