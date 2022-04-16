class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        
        int n=rains.size();
        
        //element -> index
        unordered_map<int,int> map;
        set<int> set;
        
        vector<int> res(n,1);
        
        for(int i=0;i<n;i++){
            
            int num=rains[i];
            
            if(num==0){
                set.insert(i);
            }
            else if(map.find(num) != map.end()){
                
                int index=map[num];
                auto upperIndex= set.upper_bound(index);
                
                //check if upper_bound is not found
                if(upperIndex == set.end()){
                    return {};
                }
                
                int dryIndex= *upperIndex;
                
                //update res, map, set
                res[dryIndex] = rains[i];
                res[i]=-1;
                
                map[num]=i;
                set.erase(dryIndex);
                
            }
            else{
                map[num]=i;
                res[i]=-1;
            }
        }
        
        return res;
    }
};