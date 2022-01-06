//method 1: using sorting
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        
        if(s.length() != t.length())
            return false;
        
        for(int i=0;i<s.length();i++){
            if(s[i] != t[i]) 
                return false;
        }
        
        return true;
    }
};



//method 2: using freq array
class Solution {
public:
    bool isAnagram(string s, string t) {
      
      int n1=s.size(),n2=t.size();
      
      //base case
      if(s==t) return true;
      if(n1 != n2) return false;
      
      //step1: crate a array of 26
      int freq[26]={0};
      
      for(int i=0;i<n1;i++){
        char ch1=s[i]-'a';
        char ch2=t[i]-'a';
        
        //step2: first update the s[i] to increment
        //step3: first update the t[i] to decrement
        freq[ch1]++;
        freq[ch2]--;
      }
      
      //step4: traverse the frequency array
      for(int i=0;i<26;i++){
        if(freq[i]!=0){
          return false;
        }
      }
      
      return true;
    }
};