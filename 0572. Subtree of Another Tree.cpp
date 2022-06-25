class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL) return false;
        
        if(isSame(root,subRoot)) return true;
        
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
    
    bool isSame(TreeNode* p, TreeNode* q) {
        
        //base case
        if(p==NULL && q==NULL) return true;
        if(p==NULL || q==NULL) return false;
        
        if(p->val != q->val) return false;
        
        return isSame(p->left, q->left) && isSame(p->right, q->right);
    }
};