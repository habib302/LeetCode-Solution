class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> res;
        if(root==NULL) return res;
        
        queue<TreeNode*> q;
        q.push(root);
        bool flag=true;
        
        while(q.size()>0){
            int qSize=q.size();
            vector<int> temp;
            
            for(int i=0;i<qSize;i++){
                TreeNode* curr=q.front();
                q.pop();
                temp.push_back(curr->val);
                
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            
            if(flag){
                res.push_back(temp);
            }
            else{
                reverse(temp.begin(), temp.end());
                res.push_back(temp);
            }
            
            flag= !flag;
        }
        return res;
    }
};