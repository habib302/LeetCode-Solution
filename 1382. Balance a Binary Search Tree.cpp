
class Solution {
public:
    vector<int> nums;
    TreeNode* balanceBST(TreeNode* root) {
        
        helper(root);
        
        return helper1(0,nums.size()-1);
    }
    
    void helper(TreeNode* root){
        if(root==NULL) return;
        
        helper(root->left);
        nums.push_back(root->val);
        helper(root->right);
    }
    
    TreeNode* helper1(int start, int end){
        //base case
        if(start>end) return NULL;
        
        int mid=start+(end-start)/2;
        
        TreeNode* root=new TreeNode(nums[mid]);
        root->left=helper1(start,mid-1);
        root->right=helper1(mid+1,end);
        
        return root;
    }
};