class Solution {
public:
    set<int> set;
    
    bool findTarget(TreeNode* root, int k) {
        return perOrder(root, k);
    }
    
    bool perOrder(TreeNode* root, int k){
        
        if(root==NULL) return false;
        
        int temp = k - root->val;
        
        if(set.count(temp)) return true;
        set.insert(root->val);
        
        return perOrder(root->left, k) || perOrder(root->right, k);
    }
};