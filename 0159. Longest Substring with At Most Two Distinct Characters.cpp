class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        
        int k=2;
        
        unordered_map<char,int> map;
        
        int left=0,right=0,res=0;
        
        while(right < s.size()){
            
            map[s[right]]++;
            
            while(map.size() > k){
                map[s[left]]--;
                
                //erase from map
                if(map[s[left]]==0){
                    map.erase(s[left]);
                }
                
                left++;
            }
            
            res = max(res, right-left+1);
            right++;
        }
        
        return res;
    }
};