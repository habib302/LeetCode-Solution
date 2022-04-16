class RandomizedSet {
public:
    
    //val, index in array
    unordered_map<int,int> map;
    vector<int> arr;
    
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        
        if(map.find(val) != map.end()){
            return false;
        }
        else{
            arr.push_back(val);
            map[val]=arr.size()-1;
            return true;
        }
    }
    
    bool remove(int val) {
        if(map.find(val) != map.end()){
            
            int removeIndex=map[val];
            swap(arr[removeIndex], arr[arr.size()-1]);
            
            map[arr[removeIndex]]=removeIndex;
            map.erase(val);
            arr.pop_back();
            
            return true;
        }
        else{
            return false;
        }
    }
    
    int getRandom() {
        return arr[rand() % arr.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */