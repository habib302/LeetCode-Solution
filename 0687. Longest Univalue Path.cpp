
class Solution {
public:
    int maxLength=0;
    int longestUnivaluePath(TreeNode* root) {
        if(root==NULL) return 0;
        helper(root);
        return maxLength;
    }
    
    int helper(TreeNode* root){
        //base case
        if(root==NULL) return 0;
        
        int left_tree=helper(root->left);
        int right_tree=helper(root->right);
        
        int left_check=0,right_check=0;
        
        //calculate left_check & right_check
        if(root->left!=NULL && root->val==root->left->val){
            left_check = left_tree+1;
        }
        
        if(root->right!=NULL && root->val==root->right->val){
            right_check = right_tree+1;
        }
        
        //update maxLength
        maxLength=max(maxLength, left_check+right_check);
        
        return max(left_check,right_check);
        
    }
};