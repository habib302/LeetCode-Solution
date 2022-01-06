class Solution {
public:
    bool isPalindrome(string s) {
      
      int i=0,j=s.size()-1;
      
      while(i<j){
        
        if(isalnum(s[i])==false)       i++;
        
        else if(isalnum(s[j])==false)  j--;
        
        else if(tolower(s[i]) != tolower(s[j])) return false;
        
        else {
          i++;
          j--;
        }
      }
      
      return true;
    }
};