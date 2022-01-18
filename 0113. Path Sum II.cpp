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
  vector<vector<int>> res;
  vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    //base case
    if(root==NULL) return res;
    vector<int> temp;
    
    helper(root,targetSum,temp);
    return res;
  }
  
  void helper(TreeNode* root, int targetSum,vector<int> temp){
    //base case
    if(root==NULL) return ;
    
    targetSum = targetSum - root->val;
    temp.push_back(root->val);
    
    if(root->left==NULL && root->right==NULL){
      if(targetSum==0){
        res.push_back(temp);
      }
      return ;
    }
    
    helper(root->left,targetSum,temp);
    helper(root->right,targetSum,temp);
    
    return ;
  }
};