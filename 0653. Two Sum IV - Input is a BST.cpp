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
    unordered_map<int,int> map;
    bool findTarget(TreeNode* root, int k) {
        
      return helper(root,k);
    }
    
    bool helper(TreeNode* root, int k){
      //base case
      if(root==nullptr) return false;
      
      int temp=k- (root->val);
      
      if(map.find(temp) != map.end()) return true;
      else map.insert({root->val,1});
      
      return helper(root->left,k)  || helper(root->right,k);
    }
};