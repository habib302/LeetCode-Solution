class Trie{
public:
    string word;
    bool isEnd=false;
    Trie* child[26]={NULL};
};

class Solution {
private: 
    
    void insert(string s){
        
        Trie* curr=root;
        
        for(char ch:s){
            
            int index=ch-'a';
            
            if(curr->child[index]==NULL){
                curr->child[index]=new Trie();
            }
            
            curr=curr->child[index];
        }
        curr->word=s;
        curr->isEnd=true;
    }
    
    void helper(int i, int j,Trie* root,vector<vector<char>>&board){

        if(i<0 || i>=board.size() || j<0 || j>=board[0].size())
            return ;
        
        if( board[i][j]=='*' || root->child[board[i][j]-'a']==NULL)
            return ;
        
        root=root->child[board[i][j]-'a'];
        
        //base case we found the word
        if(root->isEnd==true){
            res.push_back(root->word);
            root->isEnd=false;  //"oo" "ooa"
        }
        
        char temp_char = board[i][j];
        board[i][j]='*';
        
        helper( i+1, j,root,board);
        helper( i, j+1,root,board);
        helper(i-1, j,root,board);
        helper(i, j-1,root,board);
        
        board[i][j]=temp_char;
        
        return;
    }
    
public:
    Trie* root=new Trie();
    vector<string>res;
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        //first create the Trie
        for(auto &s:words){
            insert(s);
        }
        
        //traverse the grid 
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                
                if(root->child[board[i][j]-'a'] != NULL){
                    helper(i, j, root, board);
                }
                
            }
        }

        return res;
    }
    
};