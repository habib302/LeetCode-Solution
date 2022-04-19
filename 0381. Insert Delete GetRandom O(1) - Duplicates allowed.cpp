class RandomizedCollection {
public:
    //element->index
    unordered_map<int,set<int>> map;
    vector<int> arr;
    
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        
        //every time e insert korte habe
        // only return er type alada
        
        //present
        if(map.find(val) != map.end()){
            
            arr.push_back(val);
            map[val].insert(arr.size()-1);
            
            return false;
        }
        
        //not-present
        else{
            arr.push_back(val);
            map[val].insert(arr.size()-1);
            
            return true;
        }
    }
    
    bool remove(int val) {
        //present
        if(map.find(val) != map.end()){
            
            //get the 1st index from set
            int removeIndex= *(map[val].begin());
            
            int lastElement=arr[arr.size()-1];
            
            
            swap(arr[removeIndex], arr[arr.size()-1]);

            //age erase & pore update korbo
            
            map[val].erase(removeIndex);
            
            map[lastElement].insert(removeIndex);
            
            map[lastElement].erase(arr.size()-1);
            
            
            //check if any set is zero
            if(map[lastElement].size()==0) map.erase(lastElement);
            if(map[val].size()==0) map.erase(val);

            arr.pop_back();

            return true;
        }
        //not-present
        else{
            
            return false;
        }
    }
    
    int getRandom() {
        return arr[rand() % arr.size()]; 
    }
};
