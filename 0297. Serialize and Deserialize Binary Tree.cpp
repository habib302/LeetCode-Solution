
class Codec {
    
public:

    // Encodes a tree to a single string.
    //using preorder
    string serialize(TreeNode* root) {
        if(root==NULL) return "X";
        return to_string(root->val)+","+serialize(root->left)+","+serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        string s="";
        queue<string> q;
        
        for(char c:data){
            if(c==','){
                q.push(s);
                s="";
            }
            else{
                s = s+c;
            }
        }
        
        return makeTree(q);
    }
    
    TreeNode* makeTree(queue<string> &q){
        
        if(q.empty()) return NULL;
        
        string s=q.front();
        q.pop();
        
        if(s=="X") return NULL;
        
        TreeNode* root=new TreeNode(stoi(s));
        root->left=makeTree(q);
        root->right=makeTree(q);
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));