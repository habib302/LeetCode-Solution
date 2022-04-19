class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        
        vector<vector<int>> res;
        vector<pair<int,int>> events;
        
        for(int i=0;i<buildings.size();i++){
            
            // pair<start, -height>
            // pair<end,    height>
            events.push_back({ buildings[i][0], buildings[i][2]*(-1) });
            events.push_back({ buildings[i][1], buildings[i][2] });
        }
        
        sort(events.begin(),events.end());
        
        // for(int i=0;i<events.size();i++){
        //     cout<<events[i].first<<" "<<events[i].second<<'\n';
        // }
        
        
        //to store the heights
        //initially insert zero
        //normal set use kora jabe na multiset use korte hobe
        multiset<int> set;
        set.insert(0);
        
        int maxHeight=0,currentHeight=0;
        
        for(int i=0; i<events.size();i++){
            
            //update the heights
            if(events[i].second < 0){
                set.insert( events[i].second*(-1));
            }
            else{
                //set.erase(events[i].second);
                set.erase(set.find(events[i].second));
            }
            
            //get maxHeight from set
            currentHeight= *set.rbegin();
            
            //check currentHeight & maxHeight
            if(currentHeight != maxHeight){
                
                res.push_back({events[i].first, currentHeight});
                
                maxHeight=currentHeight;
                
            }
        }
        
        return res;
    }
};