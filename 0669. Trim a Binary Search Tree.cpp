class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        
        //base case
        if(root==NULL) return NULL;
        
        if(root->val < low) 
            return trimBST(root->right, low,high);
        
        if(root->val > high) 
            return trimBST(root->left, low,high);
        
        //check left,right sub-tree
        root->left=  trimBST(root->left, low,high);
        root->right= trimBST(root->right, low,high);
        
        return root;
    }
};