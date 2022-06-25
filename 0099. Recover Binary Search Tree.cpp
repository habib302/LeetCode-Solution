class Solution {
public:
	TreeNode* first=NULL;
    TreeNode* second=NULL;
    TreeNode* prev= new TreeNode(INT_MIN);
    
	void recoverTree(TreeNode* root) {
		
		inorder(root);
        
		swap(first->val, second->val);
	}

	void inorder(TreeNode* root) {
        
		if(root == NULL) return;

		inorder(root->left);
        
        if(first == NULL && root->val < prev->val)
			first = prev;
		if(first != NULL && root->val < prev->val)
			second = root;
        
		prev = root;

		inorder(root->right);
	}
};