class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int row=grid.size(),col=grid[0].size();
      
      int count=0;
      
      for(int r=0;r<row;r++){
        for(int c=0;c<col;c++){
          if(grid[r][c]=='1'){
            count++;
            helper(r,c,row,col,grid);
          }
        }
      }
      return count;
    }
  
  void helper(int x,int y,int r,int c,vector<vector<char>>& grid){
    
    //base case..boundary
    if(x<0 || x>=r || y<0 || y>=c) return;
    
    //base case..for '0' & '2'
    if(grid[x][y]=='0' || grid[x][y]=='2') return;
    
    //mark 1 to 2
    grid[x][y]='2';
    
    helper(x+1,y,r,c,grid);
    helper(x-1,y,r,c,grid);
    helper(x,y+1,r,c,grid);
    helper(x,y-1,r,c,grid);
  }
};