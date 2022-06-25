/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        return helper(inorder, preorder, 0,  n-1,  0,  n-1);
    }
  
  TreeNode* helper(vector<int>& inOrder, vector<int>& preOrder, int inStart, int inEnd, int preStart, int preEnd){
    //base case
    if(inStart > inEnd || preStart > preEnd) return NULL;
    
    //finde rootVal, rootIndex, leftTreeSize from inOrder
    int rootVal=preOrder[preStart];
    int rootIndex=-1;
    
    for(int i=0;i<=inEnd;i++){
      if(rootVal==inOrder[i]){
        rootIndex=i;
        break;
      }
    }
    
    int leftTreeSize=rootIndex-inStart;
    
    //construct all eight variable
    int LInStart, LInEnd, RInStart,  RInEnd;
    int LPreStart, LPreEnd, RPreStart, RPreEnd;
    
    //inOrder
    LInStart = inStart ; 
    LInEnd   = rootIndex-1;
    RInStart = rootIndex+1;
    RInEnd   = inEnd;
    
    //preOrder
    LPreStart = preStart+1;
    LPreEnd   = preStart+leftTreeSize; 
    RPreStart=  preStart+leftTreeSize+1; 
    RPreEnd  =  preEnd;
    
    //create root node, left & right subtree
    TreeNode* root = new TreeNode(rootVal);
    root->left =  helper(inOrder, preOrder, LInStart, LInEnd, LPreStart, LPreEnd);
    root->right = helper(inOrder, preOrder, RInStart, RInEnd, RPreStart, RPreEnd);
    
    //return root
    return root;
  }
};