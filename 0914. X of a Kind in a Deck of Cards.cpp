class Solution {
public:
    int gcd(int a,int b){
        if(b==0) return a;
        return gcd(b, a%b);
    }
    
    bool hasGroupsSizeX(vector<int>& deck) {
        
        unordered_map<int,int> map;
        
        //frequency map of each element
        for(int i=0;i<deck.size();i++){
            map[deck[i]]++;
        }
        
        int groupSize=0;
        
        for(auto i:map){
            groupSize = gcd(i.second, groupSize);
        }
        
        if(groupSize>=2) return true;
        return false;
    }
};