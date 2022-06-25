class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        
        //base case
        if(t1==NULL) return t2;
        if(t2==NULL)  return t1;
        
        //now we have both t1 & t2 value
        t1->val=t1->val+t2->val;
        
        //call t1 left,right
        t1->left=mergeTrees(t1->left,t2->left);
        t1->right=mergeTrees(t1->right,t2->right);
        
        //return t1 head
        return t1;
    }
};