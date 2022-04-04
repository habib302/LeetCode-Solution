
class Solution {
public:
    TreeNode* first=NULL;
    TreeNode* last=NULL;
    TreeNode* mid=NULL;
    
    TreeNode* prev=new TreeNode(INT_MIN);
    
    void recoverTree(TreeNode* root) {
        
        helper(root);
        
        if(last==NULL){
            swap(first->val, mid->val);
        }
        else{
            swap(first->val, last->val);
        }
    }
    
    void helper(TreeNode* root){
        if(root==NULL) return;
        
        helper(root->left);
        
        if(prev->val > root->val){
            if(first==NULL){
                first=prev;
                mid=root;
            }else{
                last=root;
            }
        }
        
        prev=root;
        
        helper(root->right);
    }
};