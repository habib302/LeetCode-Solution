class Solution {
public:
    int count=0;
    int countSubstrings(string s) {
        int n=s.size();
        if(n<2) return 1;
        
        for(int i=0;i<n;i++){
            helper(s,i,i);   //odd length
            helper(s,i,i+1); //even length
        }
        return count;
    }
    
    void helper(string s,int begin,int end){
        
        while(begin>=0 && end<s.size() && s[begin]==s[end]){
            count++;
            begin--;
            end++;
        }
    }
};