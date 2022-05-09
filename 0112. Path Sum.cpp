/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
      
      //base case
      if(root==NULL) return false;
      
      return helper(root,targetSum);
    }
  
  bool helper(TreeNode* root, int targetSum){
    //base case
    if(root==NULL) return false;
    
    targetSum = targetSum- (root->val);
    
    if(root->left==NULL && root->right==NULL){
      if(targetSum==0){
        return true;
      }
      else{
        return false;
      }
    }
    
    return helper(root->left,targetSum) || helper(root->right,targetSum);
  }
};