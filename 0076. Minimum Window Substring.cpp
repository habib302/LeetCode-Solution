class Solution {
public:
    string minWindow(string s, string t) {
        
        //base case
        if(s==t) 
            return s;
        if(t.size() > s.size()) 
            return "";
        
        //frequency_map of t
        unordered_map<char,int> mp;
        
        for(char ch:t){
            mp[ch]++;
        }
        
        int left=0,right=0,minLength=INT_MAX,mapSize=mp.size(),n=s.size();
        string res="";
        
        for(right=0; right<n; right++){
            
            char ch1=s[right];
            
            //step1: 1st check in map & update mapSize
            if(mp.count(ch1)){
                
                //decrease character frequency by 1
                mp[ch1]--;
                
                //if character frequency is zero
                //then we found that character all frequency
                //so, we need to decrease mapSize by 1
                if(mp[ch1]==0){
                    mapSize--;
                }
            }
            
            //step2: check mapSize
            //mapSize==0 means we found the window  
            while(mapSize==0){
                
                //check minLength & update the result
                if(minLength > right-left+1){
                    minLength = min(minLength, right-left+1);
                    res = s.substr(left, right-left+1);
                }
                
                char ch2=s[left];
                
                //update the map & mapSize
                if(mp.count(ch2)){
                    mp[ch2]++;

                    if(mp[ch2]==1){
                        mapSize++;
                    }
                }
                left++;
            }
        }
        
        return res;
    }
};