class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        vector<set<int>> row(9);
        vector<set<int>> col(9);
        vector<set<int>> box(9);
        
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                
                if(board[i][j] != '.'){
                    int val=board[i][j]-'0';
                    
                    int block = (i/3)*3 + (j/3);
                    
                    if(row[i].count(val) || col[j].count(val) || box[block].count(val)){
                        return false;
                    }
                    
                    //insert to the set
                    row[i].insert(val);
                    col[j].insert(val);
                    box[block].insert(val);
                }
            }
        }
        
        return true;
    }
};