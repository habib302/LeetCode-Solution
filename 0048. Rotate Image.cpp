class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
      int n=matrix.size();
      
      //transpose the matrix
      for(int r=0;r<n;r++){
        for(int c=r;c<n;c++){
          swap(matrix[c][r],matrix[r][c]);
        }
      }
      
      //swap the columns
      for(int r=0;r<n;r++){
        int t=0;
        for(int c=n-1;c>t;c--){
          swap(matrix[r][t],matrix[r][c]);
          t++;
        }
      }
      
    }
};