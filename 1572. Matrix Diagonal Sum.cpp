class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        
        int m=mat.size();
        if(m==1) return mat[0][0];
        
        int sum=0,r=0,c=0;
        int t=m;
        
        while(t--){
            sum += mat[r][c];
            r++;
            c++;
        }
        
        r=m-1,c=0;
        
        t=m;
        while(t--){
            sum += mat[r][c];
            r--;
            c++;
        }
        
        //if r=odd
        if(m%2==1){
            sum = sum - mat[m/2][m/2];
        }
        
        return sum;
    }
};