class Solution {
public:
    int titleToNumber(string columnTitle) {
        
        int n=columnTitle.size()-1;
        
        int res=0,temp=0;
        
        for(char ch:columnTitle){
            temp = (ch-'A') + 1;
            res = res + (temp * pow(26,n));
            n--;
        }
        
        return res;
    }
};