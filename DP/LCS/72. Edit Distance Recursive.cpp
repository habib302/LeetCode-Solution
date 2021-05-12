class Solution {
public:
    //recursion
    int minDistance(string word1, string word2) {
        return helper(0,0,word1,word2);
    }
    
    int helper(int i,int j,string& s1,string& s2){
        //base case 1
        if(i==s1.size()) return s2.size()-j;
        
        //base case 2
        if(j==s2.size()) return s1.size()-i;
        
        //choice diagaram
        if(s1[i]==s2[j]){
            return helper(i+1,j+1,s1,s2);
        }else{
            int op1 =  1 + helper(i,j+1,s1,s2);    //insert
            int op2 =  1 + helper(i+1,j,s1,s2);    //delete
            int op3 =  1 + helper(i+1,j+1,s1,s2);  //replace
            
            return min(op1, min(op2,op3));
        }
        
    }
};