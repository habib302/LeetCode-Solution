
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        
        //base case
        if(root==nullptr) return 0;
        
        //left-subtree, right-subtree
        int LeftHeight=height(root->left);
        int rightHeight=height(root->right);
        
        //left diameter, right diameter
        int Ldiameter=diameterOfBinaryTree(root->left);
        int Rdiameter=diameterOfBinaryTree(root->right);
        
        return max(LeftHeight+rightHeight, max(Ldiameter,Rdiameter));
    }
    
    int height(TreeNode* root){
        //base case
        if(root==nullptr) return 0;
        
        int left=height(root->left);
        int right=height(root->right);
        
        return max(left,right)+1;
    }
};

--------------------------------------------------------------------------------


class Solution {
public:
    int maxDiameter=0;
    int diameterOfBinaryTree(TreeNode* root) {
        
        //base case
        if(root==nullptr) return 0;
        
        height(root);
        
        return maxDiameter;
    }
    
    int height(TreeNode* root){
        //base case
        if(root==nullptr) return 0;
        
        int left=height(root->left);
        int right=height(root->right);
        
        maxDiameter= max(maxDiameter, left+right);
        
        return max(left,right)+1;
    }
};