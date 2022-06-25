class Solution {
public:
    bool pFound=false;
    bool qFound=false;
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* res = LCA(root, p,q);
        
        if(pFound && qFound){
            return res;
        }
        else return NULL;
    }
    
    TreeNode* LCA(TreeNode* root, TreeNode* p, TreeNode* q){
        
        //base case
        if(root==NULL) return root;
        
        TreeNode* left=LCA(root->left, p, q);
        TreeNode* right=LCA(root->right, p,q);
        
        //now check if p or q exist
        if(root==p){
            pFound=true;
            return root;
        }
        
        if(root==q){
            qFound=true;
            return root;
        }
        
        if(left && right){
            return root;
        }
        else if(left){
            return left;
        }
        else return right;
    }
};