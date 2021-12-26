class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        
        int n1=name.size(),n2=typed.size(),i=0,j=0;
        
        //base case 
        if(name==typed) return true;
        if(n1>n2) return false;
        
        while(i<n1 && j<n2){
            
            if(name[i]==typed[j]){
                i++;j++;
            }
            else if(i>0 && name[i-1]==typed[j]){
                j++;
            }
            else{
                return false;
            }
        }
        
        //if i<n1 but j==n2
        if(i<n1) return false;
        
        //if i==n1 but j<n2
        while(j<n2){
            if(name[n1-1]==typed[j]){
                j++;
            }
            else{
                return false;
            }
        }
        
        return true;
    }
};