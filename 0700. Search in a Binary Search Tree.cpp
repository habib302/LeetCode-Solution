class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        
        //base case
        if(root==NULL) return NULL;
        if(root->val == val) return root;
        
        if(val < root->val)
            return searchBST(root->left,val);
        
        if(val > root->val)
            return searchBST(root->right,val);
        
        return root;
    }
};