
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        
        if( abs( height(root->left) - height(root->right) ) >1 ) return false;
        
        return isBalanced(root->left) && isBalanced(root->right);
    }
    
    int height(TreeNode* root){
        if(root==NULL) return 0;
        
        return 1+max(height(root->left), height(root->right));
    }
};