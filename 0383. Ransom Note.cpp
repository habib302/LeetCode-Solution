class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        if(ransomNote.size() > magazine.size()) return false;
        
        vector<int> freq1(26,0);
        vector<int> freq2(26,0);
        
        for(char ch:ransomNote){
            freq1[ch-'a']++;
        }
        
        for(char ch:magazine){
            freq2[ch-'a']++;
        }
        
        for(int i=0;i<26;i++){
            if(freq1[i]>freq2[i])
                return false;
        }
        
        return true;
    }
};