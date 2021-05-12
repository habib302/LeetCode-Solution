class Solution {
public:
    //recursive
    int longestCommonSubsequence(string text1, string text2) {
        return helper(0,0,text1,text2);
    }
    
    int helper(int i,int j,string s1, string s2){
        //base case 1
        if(i==s1.size()) return 0;
        
        //base case 2
        if(j==s2.size()) return 0;
        
        
        //choice diagram
        if(s1[i]==s2[j]){
            return 1 + helper(i+1,j+1,s1,s2);
        }else{
            int op1 = helper(i+1,j,s1,s2);
            int op2 = helper(i,j+1,s1,s2);
            return max(op1,op2);
        }
    }
};