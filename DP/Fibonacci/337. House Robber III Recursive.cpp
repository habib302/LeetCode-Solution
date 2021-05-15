
class Solution {
public:
    
    //recursive
    int rob(TreeNode* root) {
        return helper(root);
    }
    
    int helper(TreeNode* root){
        
        //base case 1
        if(root==NULL) return 0;
        
        int val1=0,val2=0,res=0;
        
        //choice 1: root is included 
        //Then the next nodes will be... root->left->left , root->left->right, 
        //and.... root->right->left, root->right->right
        
        if(root->left != NULL){
            val1 = val1 + helper(root->left->left) + helper(root->left->right);
        }
        
        if(root->right != NULL){
            val1 = val1 + helper(root->right->left) + helper(root->right->right);
        }
        
        val1 = val1 + root->val;
        
        //choice 2: root is not included 
        val2 = helper(root->left) + helper(root->right);
        
        res = max(val1,val2);
        
        return res;
    }
};