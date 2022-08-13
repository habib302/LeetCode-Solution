class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0) 
            return false; // []=0 first condition
        
        int m,n,i,j;
        m=matrix.size(), n=matrix[0].size(); //m=row,n=column
        i=0,j=n-1;
        
        while(i>=0 && i<m && j>=0 && j<n){
            if(matrix[i][j]==target) 
                return true;
            else if(matrix[i][j] > target) 
                j--;
            else    
                i++;
        }
        
        return false;
    }
};