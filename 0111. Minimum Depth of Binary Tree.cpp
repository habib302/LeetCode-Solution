//using level order traversal
class Solution {
public:
    int minDepth(TreeNode* root) {
        
        if(root==NULL) return 0;
        
        queue<TreeNode*> q;
        q.push(root);
        
        int depth=0;
        
        while(!q.empty()){
            int n=q.size();
            depth++;
            
            for(int i=0;i<n;i++){
                TreeNode* curr=q.front();
                q.pop();
                
                if(curr->left==NULL && curr->right==NULL) return depth;
                
                if(curr->left!=NULL) q.push(curr->left);
                if(curr->right!=NULL) q.push(curr->right);
            }
        }
        
        return depth;
    }
};
---------------------------------------------------------------------------------
class Solution {
public:
    int minDepth(TreeNode* root) {
        
        //base case
        if(root==NULL) return 0;
        return minDepth2(root);
    
    }
    int minDepth2(TreeNode* root) {
        
        //base case
        if(root==NULL) return INT_MAX;
        if(root->left==NULL && root->right==NULL) return 1;
        
        int left = minDepth2(root->left);
    
        int right = minDepth2(root->right);
        
        return min(left,right)+1;
    }
};

------------------------------------------------------------------------------------
class Solution {
public:
    int minDepth(TreeNode* root) {
        
        //base case
        if(root==NULL) return 0;
        if(root->left==NULL && root->right==NULL) return 1;
        
        int left=INT_MAX, right=INT_MAX;
        
        if(root->left != NULL){
            left = minDepth(root->left);
        }
        
        if(root->right != NULL){
            right = minDepth(root->right);
        }
        
        return min(left,right)+1;
    }
};

