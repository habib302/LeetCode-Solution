class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        for(int i=0;i<board.size();i++){
            for(int j=0; j< board[0].size(); j++){
                
                if( board[i][j]==word[0] && helper(i,j,0,board,word) ){
                    return true;
                }
            }
        }
        return false;
    }
    
    bool helper(int i,int j, int index, vector<vector<char>>& board, string word){
        
        //base case 1
        if(index==word.size()) 
            return true;
        
        //base case 2
        if(i<0 || i==board.size() || j<0 || j==board[0].size()) 
            return false;
        
        //base case 3
        if(board[i][j] != word[index]) 
            return false;
        
        //otherwise character is match
        //mark as '*'
        char temp=board[i][j];
        board[i][j]='*';
        
        bool found = helper( i+1, j,  index+1, board,word) ||
                     helper( i-1, j,  index+1, board,word) ||
                     helper( i,   j+1,index+1, board,word) ||
                     helper( i,   j-1,index+1, board,word) ;
        
        //again mark as previous
        board[i][j]=temp;
        
        return found;
    }
};