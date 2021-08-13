class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int n1=name.size(),n2=typed.size();
        int i=0,j=0;
        //base case
        if(n1>n2) return false;
        if(name==typed) return true;
        
        while(i<n1 && j<n2){
            if(name[i]==typed[j]){
                i++;
                j++;
            }
            else if(i>0 && name[i-1]==typed[j]){
                j++;
            }
            else{
                return false;
            }
        }
        
        //i==n1 but j is not finished
        //name = aabbc
        //typed= aaabbccd
        while(j<n2){
            if(name[i-1]!=typed[j]){
                return false;
            }
            j++;
        }
        
        //name  = aabbcd
        //typed = aabbcc
        return (i==n1) ? true :false;
    }
};