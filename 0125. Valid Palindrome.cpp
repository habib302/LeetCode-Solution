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

--------------------------------------------------------------------------

//don't use library to check ASCII
class Solution {
public:
    bool isPalindrome(string s) {
        
        int n=s.size();
        
        if(n==1) return true;
        
        int start=0,end=n-1;
        
        while(start < end){
            
            //find the first printable ASCII character
            while((start < end) && !isASCII(s[start])){
                start++;
            }
            
            //find the last printable ASCII character
            while((start < end) && !isASCII(s[end])){
                end--;
            }
            
            if(tolower(s[start]) != tolower(s[end])) 
				return false;
            else{
                start++;
                end--;
            }
            
        }
        
        return true;
    }
    
    bool isASCII(char ch){
        
        if( (ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9') ){
            return true;
        }
        
        return false;
    }
};