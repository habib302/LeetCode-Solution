class TrieNode{
public:
    TrieNode* child[26];
    bool isEnd;
    
    TrieNode(){
        for(int i=0;i<26;i++){
            child[i]=NULL;
        }
        isEnd=false;
    }
};
class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr=root;
        
        for(char ch:word){
            
            if(curr->child[ch-'a']==NULL){
                curr->child[ch-'a']=new TrieNode();
            }
            curr=curr->child[ch-'a'];
            
        }
        curr->isEnd=true;
    }
    
    bool search(string word) {
        TrieNode* curr=root;
        
        for(char ch:word){
            
            if(curr->child[ch-'a']==NULL){
                return false;
            }
            curr=curr->child[ch-'a'];
            
        }
        return curr->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr=root;
        
        for(char ch:prefix){
            
            if(curr->child[ch-'a']==NULL){
                return false;
            }
            
            curr=curr->child[ch-'a'];
        }
        return true;
    }
};
