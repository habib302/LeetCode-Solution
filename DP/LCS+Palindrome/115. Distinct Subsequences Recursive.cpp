class Solution {
public:
    //recursive
    int numDistinct(string s, string t) {
        return helper(0,0,s,t);
    }
    
    int helper(int i,int j,string& s1, string& s2){
        //base case 1
        if(i==s1.size() && j==s2.size()) return 1;
        
        //base case 2
        if(j==s2.size()) return 1;
        
        //base case 3
        if(i==s1.size()) return 0;
        
        if(s1[i]==s2[j]){
            
            int op1 = helper(i+1,j+1,s1,s2);
            int op2 = helper(i+1,j,s1,s2);
            return op1+op2;
            
        }
        
        else{
            return helper(i+1,j,s1,s2);
        }
        
    }
};