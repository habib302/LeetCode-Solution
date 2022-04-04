//using level order traversal
#define ull unsigned long long
class Solution {
    
public:
    int widthOfBinaryTree(TreeNode* root) {
        //base case
        if(root==NULL) return 0;
        
        deque<pair<TreeNode*,ull int>> q;
        q.push_back({root,0});
        
        int maxWidth=0;
        
        while(q.size()>0){

            int n=q.size();
            int start=q.front().second;
            int end=q.back().second;
            
            maxWidth=max(maxWidth,end-start+1);
            
            for(int i=0;i<n;i++){
                TreeNode* curr=q.front().first;
                ull int parent_index=q.front().second;
                q.pop_front();
                
                if(curr->left)  { q.push_back({curr->left,2*parent_index+1}); }
                if(curr->right) { q.push_back({curr->right,2*parent_index+2}); }
                
            }
        }
        
        return maxWidth;
    }
};