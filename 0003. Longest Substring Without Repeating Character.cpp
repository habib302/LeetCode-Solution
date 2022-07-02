//method: sliding window
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        //char->frequency
        unordered_map<char,int> mp;
        
        int left=0,right=0,res=0,n=s.size();
        
        for(right=0; right<n; right++){
            
            char ch=s[right];
            
            //update frequency
            mp[ch]++;
            
            //remove until 
            while(mp[ch] > 1){
                
                //decrease left character frequency by 1
                mp[s[left]]--;
                
                //if chracter frequency is zero 
                //then remove key from map
                if(mp[s[left]]==0){
                    mp.erase(s[left]);
                }
                
                //update left by 1
                left++;
            }
            
            res = max(res, right-left+1);
        }
        
        return res;
    }
};