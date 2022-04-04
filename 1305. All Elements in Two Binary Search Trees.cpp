
class Solution {
public:
    vector<int> nums;
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        helper(root1);
        helper(root2);
        
        sort(nums.begin(),nums.end());
        return nums;
    }
    
    void helper(TreeNode* root){
        if(root==NULL) return;
        
        helper(root->left);
        nums.push_back(root->val);
        helper(root->right);
    }
};