class NestedIterator {
    vector<int> res;
    int curr=0;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        helper(nestedList);
    }
    
    int next() {
        return res[curr++];
    }
    
    bool hasNext() {
        return curr<res.size();
    }
    
    void helper(vector<NestedInteger> &nestedList){
        
        for(auto x:nestedList){
            if(x.isInteger()){
                res.push_back(x.getInteger());
            }
            else{
                helper(x.getList());
            }
        }
    }
};
