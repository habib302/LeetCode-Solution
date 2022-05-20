class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        //base case
        if(root==NULL) return NULL;
        
        if(root==p || root==q) return root;
        
        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        TreeNode* right=lowestCommonAncestor(root->right,p,q);
        
        if(left&&right) return root;
        return left==NULL ? right :left;
    }
};