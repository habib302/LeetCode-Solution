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
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        
        int left=height(root->left);
        int right=height(root->right);
        
        if(abs(left-right)>1) return false;
        
        return isBalanced(root->left) && isBalanced(root->right);
    }
    
    int height(TreeNode* root){
        //base case
        if(root==NULL) return 0;
        
        int left=height(root->left);
        int right=height(root->right);
        
        return max( left,right )+1; 
    }
};

---------------------------------------------------------------------------
class Solution {
public:
    
    //assume that tree is balanced
    bool res=true;
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        
        height(root);
        
        return res;
    }
    
    int height(TreeNode* root){
        //base case
        if(root==NULL || res==false) return 0;
        
        int left=height(root->left);
        int right=height(root->right);
        
        if(abs(left-right)>1){
            res=false;
        }
        
        return max(left,right )+1; 
    }
};