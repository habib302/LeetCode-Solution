
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        //base case
        if(nums.size()==0) return NULL;
        
        int max_index=0,max_value=nums[0];
        
        //find the max_index & max_value
        for(int i=1;i<nums.size();i++){
            if(max_value<nums[i]){
                max_value=nums[i];
                max_index=i;
            }
        }
        
        //slice the two array
        vector<int> nums1(nums.begin()+ 0,           nums.begin()+max_index );
        vector<int> nums2(nums.begin()+ max_index+1, nums.end()             );
        
        TreeNode* root= new TreeNode(nums[max_index]);
        
        root->left= constructMaximumBinaryTree(nums1);
        root->right= constructMaximumBinaryTree(nums2);
        
        return root;
    }
};