class Solution {
public:
    bool isValid(int row,int col,int val,vector<vector<char>>& board){
        //check row & col
        for(int i=0;i<9;i++){
            
            //check col
            if(board[row][i]==val)
                return false;
            
            //check row
            if(board[i][col]==val)
                return false;
        }
        
        //normalize r & c
        int x = (row/3)*3 , y =(col/3)*3;
        
        //check 3*3 box
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                
                if(board[x+i][y+j]==val)
                    return false;
            }
        }
        return true;
    }
    
    bool helper(int row,int col,vector<vector<char>>& board){
        //base case 1
        if(row==9) 
            return true;
        
        if(col==9) 
            return helper(row+1,0,board);
        
        if(board[row][col]!= '.')
            return  helper(row,col+1,board);  
        
        for(char ch='1'; ch<='9';ch++){
            
            if(isValid(row,col,ch,board)){
                
                board[row][col]=ch;
                
                if(helper(row,col+1,board))
                    return true;
                
                board[row][col]='.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        helper(0, 0,board);
    }
};