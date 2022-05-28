class Solution {
public:
    
    vector<vector<int>> verticalOrder(TreeNode* root) {
        
        //col, val
        unordered_map<int, vector<int>> map;
        
        vector<vector<int>> res;
        if(root==NULL) return res;
        
        //TreeNode, col
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        
        int leftCol=0,rightCol=0;
        
        while(q.size()>0){
            int n=q.size();
            
            for(int i=0;i<n;i++){
                TreeNode* curr=q.front().first;
                int col=q.front().second;
                q.pop();
                
                map[col].push_back(curr->val);
                
                if(curr->left != NULL) {
                    q.push({curr->left, col-1});
                    leftCol = min(leftCol, col-1); 
                }
                if(curr->right != NULL) {
                    q.push({curr->right, col+1});
                    rightCol = max(rightCol, col+1); 
                }
            }
        }
        
        for(int i=leftCol;i<=rightCol;i++){
            vector<int> temp=map[i];
            res.push_back(temp);
        }
        return res;
    }
};