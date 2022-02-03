class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        //base case
        if(root==NULL) return NULL;
        
        if(root->val > key){
            root->left = deleteNode(root->left, key);
        }
        else if(root->val < key){
            root->right = deleteNode(root->right, key);
        }
        //root->val equals to key
        else{
            
            //case 1:
            if(root->left==NULL && root->right==NULL) return NULL;
            
            //case 2:
            else if(root->right==NULL) return root->left;
            
            //case 3:
            else if(root->left==NULL) return root->right;
            
            //case 4:
            else{
                TreeNode* curr=root->left;
                int leftMax=INT_MIN;
                
                //step 1: find the leftMax
                
                while(curr!=NULL){
                    leftMax=max( leftMax, curr->val);
                    curr=curr->right;
                }
                
                //step 2: update root->val with leftMax 
                root->val=leftMax;
                
                //step 3: now call root->left to delete leftMax
                root->left=deleteNode(root->left, leftMax);
            }
        }
        
        return root;
    }
};