class RandomizedSet {
public:
    //element->index
    unordered_map<int,int> map;
    vector<int> arr;
    
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        
        //present
        if(map.find(val) != map.end()){
            return false;
        }
        
        //not-present
        else{
            arr.push_back(val);
            map[val]=arr.size()-1;
            
            return true;
        }
    }
    
    bool remove(int val) {
        //present
        if(map.find(val) != map.end()){
            
            int removeIndex=map[val];
            int lastElement=arr[arr.size()-1];
            
            swap(arr[removeIndex], arr[arr.size()-1]);
            
            //age update & pore erase korbo
            //removeIndex==arr.size()-1 
            //pore update korle removeIndex abar add hoy jabe
            map[lastElement]=removeIndex;
            map.erase(val);
            
            arr.pop_back();
            
            return true;
        }
        //not-present
        else{
            
            return false;
        }
        
    }
    
    int getRandom() {
       return arr[rand()%arr.size()]; 
    }
};
