class Solution {
public:
    string minWindow(string s, string t) {
        
        //base case
        if(s==t) return s;
        if(t.size() > s.size()) return "";
        
        unordered_map<char,int> map;
        
        for(char ch:t){
            map[ch]++;
        }
        
        int i=0,j=0,minLength=INT_MAX,mapSize=map.size();
        string res="";
        
        while(j < s.size()){
            char ch=s[j];
            
            //step1: 1st check in map & update mapSize
            if(map.find(ch) != map.end()){
                map[ch]--;
                
                if(map[ch]==0){
                    mapSize--;
                }
            }
            
            //step2: check mapSize
            //mapSize==0 means we found the window  
            while(mapSize==0){
                
                //check minLength
                if(minLength > j-i+1){
                    minLength = min(minLength, j-i+1);
                    res = s.substr(i, j-i+1);
                }
                
                //update the map & mapSize
                if(map.find(s[i]) != map.end()){
                    map[s[i]]++;

                    if(map[s[i]]==1){
                        mapSize++;
                    }
                }
                i++;
            }
            
            //step3: increase the window end
            j++;
        }
        
        return res;
    }
};