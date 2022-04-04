class Solution {
public:
    Node* connect(Node* root) {
        
        //base case
        if(root==NULL) return NULL;
        
        //using level order traversal
        queue<Node*> q;
        q.push(root);
        
        while(q.size()>0){
            int n=q.size();
            Node* prev=NULL;
            
            for(int i=0;i<n;i++){
                
                Node* curr=q.front();
                q.pop();
                
                //check prev is not NULL
                if(prev!=NULL) prev->next=curr;
                
                //push curr-> left,right to queue
                if(curr->left != NULL) q.push(curr->left);
                if(curr->right != NULL) q.push(curr->right);
                
                //update the prev
                prev=curr;
            }
        }
        
        return root;
        
    }
};