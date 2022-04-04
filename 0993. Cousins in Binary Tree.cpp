//using level order traversal
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(q.size()>0){
            int n=q.size();
            TreeNode* parent1=NULL;
            TreeNode* parent2=NULL;
            
            for(int i=0;i<n;i++){
                TreeNode* curr=q.front();
                q.pop();
                
                
                if(curr->left) {
                    q.push(curr->left);
                    
                    if(curr->left->val==x || curr->left->val==y){
                        if(parent1){
                            parent2=curr;
                        }else{
                            parent1=curr;
                        }
                    }
                }
                
                if(curr->right) {
                    q.push(curr->right);
                    
                    if(curr->right->val==x || curr->right->val==y){
                        if(parent1){
                            parent2=curr;
                        }else{
                            parent1=curr;
                        }
                    }
                }
            }
            
            if(parent1 && parent2){
                if(parent1 != parent2) return true;
            }
        }
        
        return false;
    }
};