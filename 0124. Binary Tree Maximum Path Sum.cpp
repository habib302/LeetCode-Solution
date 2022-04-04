
class Solution {
public:
    int maxSum=INT_MIN;
    int maxPathSum(TreeNode* root) {
        helper(root);
        return maxSum;
    }
    
    int helper(TreeNode* root){
        //base case
        if(root==NULL) return 0;
        
        int left=max(helper(root->left),0);
        int right=max(helper(root->right),0);
        
        int currSum=root->val+left+right;
        
        maxSum=max(maxSum,currSum);
        
        return max(root->val+left, root->val+right);
    }
};