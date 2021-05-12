class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size() != s3.size()) return false;
        return helper(0,0,0,s1,s2,s3);
    }
    
    bool helper(int i,int j,int k,string& s1, string& s2, string& s3){
        
        //base case 1
        if(i==s1.size() && j==s2.size() && k==s3.size()) return true;
        
        bool res=false;
        
        //choice diagram
        if(i<s1.size() && s1[i]==s3[k]){
            res = res || helper(i+1,j,k+1,s1,s2,s3);
        }
        
        if(j<s2.size() && s2[j]==s3[k]){
            res = res || helper(i,j+1,k+1,s1,s2,s3);
        }
        
        return res;
    }
};