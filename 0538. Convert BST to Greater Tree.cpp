
class Solution {
public:
    int sum=0;
    TreeNode* convertBST(TreeNode* root) {
        //base case
        if(root==NULL) return NULL;
        
        convertBST(root->right);
        
        sum=sum+root->val;
        root->val=sum;
        
        convertBST(root->left);
        
        return root;
    }
    
};