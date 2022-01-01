class Solution {
public:
    bool isIsomorphic(string s, string t) {
      //base case
      if(s==t) return true;
      
      //step1: initialize two array with zero
      int m1[256]={0},m2[256]={0},n=s.size();
      
      for(int i=0;i<n;i++){
        char ch1=s[i];
        char ch2=t[i];
        
        //step2: if m1[ch1] are not equal to m2[ch2] reurn false
        if(m1[ch1] != m2[ch2]) return false;
        
        //step3: update m1[ch1] & m2[ch2] with same value
        m1[ch1]=i+1;
        m2[ch2]=i+1;
      }
      
      return true;
    }
};