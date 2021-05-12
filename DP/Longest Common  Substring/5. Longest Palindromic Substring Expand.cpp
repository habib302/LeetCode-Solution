class Solution {
public:
    int start,maxLength;
    string longestPalindrome(string s) {
        int n=s.size();
        
        if(n<2) return s;
        
        for(int i=0;i<n;i++){
            
            // abcba
            helper(s,i,i);
            
            //abccba
            helper(s,i,i+1);
        }
        return s.substr(start,maxLength);
    }
    
    void helper(string s,int begin,int end){
        while(begin>=0 && end<s.size() && s[begin] ==s[end]){
            begin--;
            end++;
        }
        
        if(maxLength < end-begin-1){
            start=begin+1;
            maxLength = end-begin-1;
        }
    }
};