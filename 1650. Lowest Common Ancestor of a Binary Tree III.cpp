class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        
        set<Node*> set;
        
        while(p != NULL){
            set.insert(p);
            p = p->parent;
        }
        
        while(q != NULL){
            
            //check is set
            if(set.count(q)){
                return q;
            }
            
            q = q->parent;
        }
        
        return NULL;
    }
};