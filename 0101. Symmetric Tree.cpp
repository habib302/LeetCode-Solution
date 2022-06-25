class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        return isSame(root->left, root->right);
    }
    
    bool isSame(TreeNode* p,TreeNode* q){
        
        //base case
        if(p==NULL && q==NULL) return true;
        if(p==NULL || q==NULL) return false;
		
        if(p->val != q->val) return false;
        
        return isSame(p->left,q->right) && isSame(p->right,q->left);
    }
};