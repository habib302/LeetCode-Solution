class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int n=matrix.size();
        
		//transpose of the matrix
        for(int r=0;r<n;r++){
            for(int c=r;c<n;c++){
                swap(matrix[r][c], matrix[c][r]);
            }
        }
        
		//swap the column
        for(int r=0;r<n;r++){
            int c1=0,c2=n-1;
            
            while(c1<c2){
                swap(matrix[r][c1], matrix[r][c2]);
                c1++;
                c2--;
            }
        }
        
    }
};