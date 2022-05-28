class TimeMap {
    
    // key -> {value, timestamp}
    unordered_map<string, vector<pair<string,int>>> map;
public:
    string binarySearch(vector<pair<string,int>> &temp, int &timestamp){
        
        int start=0,end=temp.size()-1;
        
        //case 1:
        if(temp[end].second <= timestamp) return temp[end].first;
        
        //case 2:
        if(temp[start].second > timestamp) return "";
        
        while(start <= end){
            int mid=start + (end-start)/2;
            
            if(temp[mid].second==timestamp){
                return temp[mid].first;
            }
            else if(temp[mid].second > timestamp){
                end=mid-1;
            }
            else start=mid+1;
        }
        
        return end >= 0 ? temp[end].first : "";
    }
    
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        map[key].push_back({value,timestamp});
    }
    
    string get(string key, int timestamp) {
        
        //present
        if(map.find(key) != map.end()){
            return binarySearch(map[key], timestamp);
        }
        else return "";
    }
};
