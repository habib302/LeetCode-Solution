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
    bool isUnivalTree(TreeNode* root) {
      
      return helper(root, root->val);
    }
    
    bool helper(TreeNode* root, int num){
      //base case
      if(root==nullptr) return true;
      
      if(root->val != num) return false;
      
      return helper(root->left,num) && helper(root->right,num);
    }
};