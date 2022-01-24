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
  int count=0;
  int pathSum(TreeNode* root, int targetSum) {
    //base case
    if(root==NULL) return 0;
    
    helper(root,targetSum);
    pathSum(root->left, targetSum);
    pathSum(root->right, targetSum);
    
    return count;
  }
  
  void helper(TreeNode* root, int targetSum){
    //base case
    if(root==NULL) return;
    
    if(targetSum==root->val){
      count++;
    }
    
    helper(root->left,targetSum - root->val);
    helper(root->right,targetSum - root->val);
    return;
  }
};