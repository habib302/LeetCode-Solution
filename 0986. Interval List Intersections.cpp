class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        
        int n1=firstList.size(),n2=secondList.size();
        vector<vector<int>> res;
        
        //base case
        if(n1==0 || n2==0) return res;
        
        int s1,e1,s2,e2,ptr1=0,ptr2=0,CSP,CEP;
        
        while(ptr1<n1 && ptr2<n2){
            s1=firstList[ptr1][0];
            e1=firstList[ptr1][1];
            s2=secondList[ptr2][0];
            e2=secondList[ptr2][1];
            
            //common start point & end point
            CSP = max(s1,s2);
            CEP = min(e1,e2);
            
            //check CSP & CEP .... then push 
            if(CSP <= CEP){
                vector<int> temp={CSP,CEP};
                res.push_back(temp);
            }
            
            //increse the ptr1 or ptr2
            if(e1<e2) {  ptr1++; } 
            else      {  ptr2++; }
        }
        
        return res;
    }
};