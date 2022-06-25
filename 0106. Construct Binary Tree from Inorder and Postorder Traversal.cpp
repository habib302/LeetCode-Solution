class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=postorder.size();
        return helper(0,n-1,0,n-1, inorder,postorder);
    }
    
    TreeNode* helper(int inStart, int inEnd, int postStart, int postEnd, vector<int>& inOrder,vector<int>& postOrder){
        //base case
        if(inStart>inEnd || postStart>postEnd) return NULL;
        
        int rootVal=postOrder[postEnd];
        int rootIndex=-1;
        
        for(int i=0;i<=inEnd;i++){
            if(rootVal==inOrder[i]){
                rootIndex=i;
                break;
            }
        }
        
        int leftTreeSize=rootIndex- inStart;
        
        int LInStart,LInEnd,RInStart,RInEnd;
        int LPostStart,LPostEnd,RPostStart,RPostEnd;
        
        //construct inOrder 
        LInStart=inStart;
        LInEnd=rootIndex-1;
        RInStart=rootIndex+1;
        RInEnd=inEnd;
        
        LPostStart=postStart;
        LPostEnd=postStart+leftTreeSize-1;  //zero based index
        RPostStart=postStart+leftTreeSize;
        RPostEnd=postEnd-1;
        
        TreeNode* root=new TreeNode(rootVal);
        root->left = helper(LInStart,LInEnd,LPostStart,LPostEnd,inOrder,postOrder);
        root->right = helper(RInStart,RInEnd,RPostStart,RPostEnd,inOrder,postOrder);
        
        return root;
    }
};