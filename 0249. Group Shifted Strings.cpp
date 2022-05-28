class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        
        unordered_map<string, vector<string>> map;
        
        for(auto s:strings){
            string key = getKey(s);
            
            map[key].push_back(s);
        }
        
        vector<vector<string>> res;
        
        for(auto i:map){
            res.push_back(map[i.first]);
        }
        
        return res;
    }
    
    string getKey(string &s){
        
        string key="";
        if(s.size()==1) return "#";
        
        for(int i=1;i<s.size();i++){
            int curr=s[i]-'a';
            int prev=s[i-1]-'a';
            
            int diff=curr-prev;
            
            if(diff<0){
                diff = diff+26;
            }
            
            key = key + to_string(diff) + "#";
        }
        
        return key;
    }
};