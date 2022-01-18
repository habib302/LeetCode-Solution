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
    vector<string> res;
  
    vector<string> binaryTreePaths(TreeNode* root) {
      string temp="";
      helper(root,temp);
      return res;
    }
  
    void helper(TreeNode* root,string temp){
      //base case
      if(root==NULL) return;
      temp = temp +"->"+ to_string(root->val);
      
      if(root->left==NULL && root->right==NULL){
        temp.erase(0,2);
        res.push_back(temp);
        return ;
      }

      helper(root->left,temp);
      helper(root->right,temp);
      return ;
    }
};