// TC= O(n)
// SC= O(n)
class Solution {
public:
    vector<int> res;
    bool isValidBST(TreeNode* root) {
        inOrder(root);
        
        for(int i=1;i<res.size();i++){
            if(res[i-1] >= res[i]){
                return false;
            }
        }
        
        return true;
    }
    
    void inOrder(TreeNode* root){
        
        if(root==NULL) return;
        
        inOrder(root->left);
        res.push_back(root->val);
        inOrder(root->right);
    }
};



class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return helper(root,  LONG_MIN, LONG_MAX);
    }
    
    bool helper(TreeNode* root, long minVal, long maxVal){
        //base case
        if(root==NULL) return true;
        
        if(minVal >= root->val || root->val >=  maxVal) return false;
        
        return helper(root->left,  minVal,     root->val) &&
               helper(root->right, root->val,  maxVal);
    }
};