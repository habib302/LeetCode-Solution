class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
      
      int n1=s.size(),n2=p.size();
      vector<int> res,freq1(26,0),freq2(26,0) ;
      
      //base case
      if(n2>n1) return res;
      
      //step1: create frequency array for p
      for(char ch:p){
        freq2[ch-'a']++;
      }
      
      //step2: traverse s
      for(int i=0;i<n1;i++){
        char ch=s[i];
        
        //insert character in freq array
        freq1[ch-'a']++;
        
        //if(i>=window size) remove lower-end character
        if(i>=n2) freq1[s[i-n2]-'a']--;
        
        //check if anagram
        if(freq1==freq2) res.push_back(i-n2+1);
      }
      
      return res;
    }
};