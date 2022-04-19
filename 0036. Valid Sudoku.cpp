class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        
        //check row
        for(int r=0;r<9;r++){
            
            set<char> set;
            for(int c=0;c<9;c++){
                if(board[r][c]=='.'){
                    continue;
                }
                else{
                    if(set.count(board[r][c])){
                        return false;
                    }
                    else{
                        set.insert(board[r][c]);
                    }
                }
            }
        }
        
        cout<<"row"<<'\n';
        
        //check col
        for(int c=0;c<9;c++){
            
            set<char> set;
            for(int r=0;r<9;r++){
                if(board[r][c]=='.'){
                    continue;
                }
                else{
                    if(set.count(board[r][c])){
                        return false;
                    }
                    else{
                        set.insert(board[r][c]);
                    }
                }
            }
        }
        cout<<"col"<<'\n';
        
        //check 3*3 sub-box
        vector<pair<int,int>> arr{{0,0},{0,3},{0,6},
                                  {3,0},{3,3},{3,6},
                                  {6,0},{6,3},{6,6}};
        
        for(int i=0;i<arr.size();i++){
            int r=arr[i].first;
            int c=arr[i].second;
            
            cout<<r<<" "<<c<<'\n';
            
            set<char> set;
            
            for(int row=r;row<r+3;row++){
                
                for(int col=c;col<c+3;col++){
                    
                    if(board[row][col]=='.'){
                        continue;
                    }
                    else{
                        if(set.count(board[row][col])){
                            return false;
                        }
                        else{
                            set.insert(board[row][col]);
                        }
                    }
                }
            }
        }
        
        return true;
    }
};