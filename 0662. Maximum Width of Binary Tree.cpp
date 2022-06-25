#define ulli unsigned long long int
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        
        //base case
        if(root==NULL) return 0;
        
        deque<pair<TreeNode*, ulli>> q;
        q.push_back({root,0});
        
        int maxWidth=0;
        
        while(q.size()>0){
            int qSize=q.size();
            
            int start=q.front().second;
            int end=q.back().second;
            
            maxWidth = max(maxWidth, end-start+1);
            
            for(int i=0;i<qSize;i++){
                TreeNode* curr=q.front().first;
                ulli index=q.front().second;
                q.pop_front();
                
                if(curr->left !=NULL){
                    q.push_back({curr->left, 2*index+1});
                }
                if(curr->right !=NULL){
                    q.push_back({curr->right, 2*index+2});
                }
            }
        }
        
        return maxWidth;
        
    }
};