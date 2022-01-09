//method 1: using create a nums vector by inOrder then create the tree
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
  vector<int> nums;
    TreeNode* increasingBST(TreeNode* root) {
      inOrder(root);
      int n=nums.size();
      TreeNode* new_head= new TreeNode(nums[0]);
      TreeNode* curr=new_head;
      
      for(int i=1;i<n;i++){
        curr->right = new TreeNode(nums[i]);
        curr=curr->right;
      }
      
      return new_head;
    }
    
  void inOrder(TreeNode* root){
    //base case
    if(root==nullptr) return;
    
    inOrder(root->left);
    nums.push_back(root->val);
    inOrder(root->right);
  }
};