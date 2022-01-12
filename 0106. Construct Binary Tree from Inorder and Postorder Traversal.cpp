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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
       int n=inorder.size();
      return helper(inorder, postorder, 0, n-1, 0, n-1);
    }
  
  TreeNode* helper(vector<int>& inOrder, vector<int>& postOrder,int inStart, int inEnd, int postStart, int postEnd){
    //base case
    if(inStart > inEnd) return NULL;
    
    //finde rootVal, rootIndex, leftTreeSize from inOrder
    int rootVal=postOrder[postEnd];
    int rootIndex= -1;
    
    for(int i=0;i<=inEnd;i++){
      if(rootVal==inOrder[i]){
        rootIndex=i;
        break;
      }
    }
    
    int leftTreeSize=rootIndex-inStart;
    
    //construct all eight variable
    int LInStart, LInEnd, RInStart, RInEnd;
    int LPostStart, LPostEnd, RPostStart, RPostEnd;
    
    LInStart  = inStart; 
    LInEnd    = rootIndex-1; 
    RInStart = rootIndex+1; 
    RInEnd   = inEnd;
    
    LPostStart = postStart; 
    LPostEnd   = postStart+leftTreeSize-1; 
    RPostStart= postStart+leftTreeSize; 
    RPostEnd  = postEnd-1;
    
    //create root node, left & right subtree
    TreeNode* root = new TreeNode(rootVal);
    root->left = helper(inOrder,  postOrder, LInStart,  LInEnd, LPostStart, LPostEnd);
    root->right = helper(inOrder, postOrder, RInStart,  RInEnd, RPostStart, RPostEnd);
    
    //return root
    return root;
  }
};