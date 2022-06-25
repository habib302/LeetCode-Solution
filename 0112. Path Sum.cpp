class Solution {
public:

    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL) 
            return false;
        
        return helper(root, targetSum, 0);
    }
    
	//preorder e calculation korbo
    bool helper(TreeNode* root, int targetSum,int sum) {
        
        //base case 
        if(root==NULL)
            return false;
        
        sum = sum + root->val;
        if(root->left==NULL && root->right==NULL && targetSum==sum){
            return true;
        }
        
        return helper(root->left, targetSum, sum) || 
               helper(root->right, targetSum, sum) ;
    }
};