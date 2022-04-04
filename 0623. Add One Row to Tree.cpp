
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        if(depth==1){
            TreeNode* curr=new TreeNode(val);
            curr->left=root;
            return curr;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        int level=1;
        
        while(q.size()>0){
            int n=q.size();
            
            if(level==depth-1) break;
            level++;
            
            for(int i=0;i<n;i++){
                TreeNode* curr=q.front();
                q.pop();
                
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        }
        
        while(q.size()>0){
            TreeNode* curr=q.front();
            q.pop();
            
            TreeNode* temp1=new TreeNode(val); 
            TreeNode* temp2=new TreeNode(val); 
            
            temp1->left=curr->left;
            curr->left=temp1;
            
            temp2->right=curr->right;
            curr->right=temp2;
        }
        
        return root;
    }
};