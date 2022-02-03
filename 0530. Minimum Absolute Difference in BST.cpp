
class Solution {
public:
    vector<int> res;
    int getMinimumDifference(TreeNode* root) {
        
        inOrder(root);
        
        int minVal=INT_MAX;
        
        for(int i=1;i<res.size();i++){
            minVal = min(minVal, abs(res[i]-res[i-1]));
        }
        
        return minVal;
    }
    
    void inOrder(TreeNode* root){
        if(root==NULL) return;
        
        inOrder(root->left);
        res.push_back(root->val);
        inOrder(root->right);
    }
};


class Solution {
public:
    int minVal=INT_MAX;
    int prev=INT_MAX;
    
    int getMinimumDifference(TreeNode* root) {
        
        inOrder(root);
        
        return minVal;
    }
    
    //inOrder traversal
    void inOrder(TreeNode* root){
        
        //base case
        if(root==NULL) return;
        
        inOrder(root->left);
        
        minVal = min(minVal, abs(prev-root->val));
        prev=root->val;
        
        
        inOrder(root->right);
    }
};