class Solution {
public:
    string countAndSay(int n) {
        
        //base case
        if(n==1) return "1";
        if(n==2) return "11";
        
        string s="11";
        
        for(int i=3; i<=n;i++){
            
            //add one extra character
            //if all the character are same
            s = s + '@';
            
            int len=s.size(),count=1;
            
            string temp="";
            
            for(int j=1;j<len;j++){
                
                if(s[j-1] != s[j]){
                    temp = temp + to_string(count);
                    temp = temp + s[j-1];
                    count= 1;
                }
                else count++;
            }
            
            s = temp;
        }
        
        return s;
    }
};