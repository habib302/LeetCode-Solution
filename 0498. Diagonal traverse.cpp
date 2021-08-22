class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        
        int m=mat.size(),n=mat[0].size(),r=0,c=0;
        vector<int> res(m*n,0);
        
        for(int i=0;i<m*n;i++){
            
            //push to re
            res[i]=mat[r][c];
            
            //even...for up
            if((r+c)%2==0){
                
                //prothom duita corner case
                if(c==n-1)      { r++; }
                else if(r==0)   { c++; }
                else            { c++;r--;}
            }
            //odd...for down
            else{
                
                //prothom duita corner case
                if(r==m-1)         { c++; }
                else if(c==0)      { r++; }
                else               { c--;r++;}
                
            }
        }
        
        return res;
    }
};