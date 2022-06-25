class Solution {
public:
    vector<vector<int>> res;
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root==NULL) 
            return res;
        
        vector<int> temp;
        
        helper(targetSum, 0, temp, root);
        
        return res;
    }
    
     void helper(int targetSum,int sum, vector<int> temp, TreeNode* root ) {
        
        //base case 
        if(root==NULL)
            return;
        
        sum = sum + root->val;
        temp.push_back(root->val);
         
        if(root->left==NULL && root->right==NULL && targetSum==sum){
            res.push_back(temp);
            return ;
        }
        
        helper( targetSum, sum, temp, root->left  );
        helper( targetSum, sum, temp, root->right ) ;
    }
};