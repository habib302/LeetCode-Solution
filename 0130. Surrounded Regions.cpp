class Solution {
public:
    void solve(vector<vector<char>>& board) {
        
        int m=board.size(), n= board[0].size();
        
        //traverse 1st & last column
        for(int i=0;i<m;i++){
            
            //first col
            if(board[i][0]=='O')   helper(board,i ,0 ,m,n);
            
            //last col
            if(board[i][n-1]=='O') helper(board,i ,n-1,m,n);

        }
        
        //traverse 1st & last row
        for(int j=0;j<n;j++){
            
            //first row
            if(board[0][j]=='O')   helper(board,0,j,m,n);
            
            //last row
            if(board[m-1][j]=='O') helper(board,m-1,j,m,n);
        }
        
        //travse the full board
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                
                //first convert '0' to 'X'
                if(board[i][j]=='O')  board[i][j]='X';
                
                //then convert '#' to 'O'
                if(board[i][j]=='#')  board[i][j]='O';
                
            }
        }
    }
    
    void helper(vector<vector<char>>& board, int i,int j,int m,int n){
        
        //base case
        if(i<0 ||  i>=m || j<0 || j>=n || board[i][j]!='O' ) return;
        
        //convert 'O' to '#'
        board[i][j]='#';
        
        helper(board, i+1, j  ,m,n);
        helper(board, i-1, j  ,m,n);
        helper(board, i  , j+1,m,n);
        helper(board, i  , j-1,m,n);
    }
};