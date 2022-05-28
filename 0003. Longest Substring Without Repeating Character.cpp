//method: sliding window
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_map<char,int> map;
        
        int left=0,right=0,res=0;
        
        while(right < s.size()){
            
            map[s[right]]++;
            
            //remove until 
            while(map[s[right]] > 1){
                
                map[s[left]]--;
                left++;
            }
            
            res = max(res, right-left+1);
            right++;
        }
        
        return res;
    }
};