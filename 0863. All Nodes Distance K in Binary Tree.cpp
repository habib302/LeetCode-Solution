//node,parent
unordered_map<TreeNode*,TreeNode*> parentMap;

class Solution {
public:
    //first map the map
    void helper(TreeNode* root){
        if(root==NULL) return;
        
        if(root->left != NULL){
            parentMap.insert({root->left, root});
        }
        
        if(root->right != NULL){
            parentMap.insert({root->right, root});
        }
        
        helper(root->left);
        helper(root->right);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> res;
        
        helper(root);
        
        // Hash to store the nodes which are already visited so we do not fall in an infinite loop
        unordered_map<TreeNode*, bool> visited;
        
        //using level order traver
        queue<TreeNode*> q;
        q.push(target);
        
        int currentLevel=-1;
        
        while(q.size()>0){
            int qSize=q.size();
            currentLevel++;
            
            for(int i=0;i<qSize;i++){
                TreeNode* curr=q.front();
                q.pop();
                
                visited[curr]=true;
                
                if(currentLevel==k){
                    res.push_back(curr->val);
                }
                
                if(curr->left!=NULL && visited[curr->left]==false){
                    q.push(curr->left);
                }
                
                if(curr->right!=NULL && visited[curr->right]==false){
                    q.push(curr->right);
                }
                
                if(parentMap[curr] && visited[parentMap[curr]]==false){
                    q.push(parentMap[curr]);
                }
            }
            
            if(currentLevel==k)
                break;
        }
        
        return res;
    }
};