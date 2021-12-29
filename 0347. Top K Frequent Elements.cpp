#define pii pair<int,int>
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        
        //map the number & their frequency
        for(int i=0;i<nums.size();i++){
            map[nums[i]]++;
        }
        vector<int> result;
        priority_queue<pii, vector<pii>, greater<pii>> minHeap;
        
        for(auto i=map.begin(); i != map.end() ; i++){
            minHeap.push({i->second,i->first});
            if(minHeap.size()>k){
                minHeap.pop();
            }
        }
        
        while(minHeap.size() > 0){
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }
        
        return result;
    }
};