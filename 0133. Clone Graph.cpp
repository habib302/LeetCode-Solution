class Solution {
public:
    Node* cloneGraph(Node* node) {
        
        //base case
        if(node==NULL) return NULL;
        
        unordered_map<Node*,Node*> map;
        
        Node* first = new Node(node->val);
        map[node] = first;
        
        queue<Node*> q;
        q.push(node);
        
        while(q.size()>0){
            Node* curr=q.front();
            q.pop();
            
             // now travel in adjcant
             for(auto adj: curr -> neighbors){
                 
                // if not present in map
                if(map.find(adj) == map.end()){
                    Node* temp = new Node(adj->val);
                    map[adj] = temp;        // then create copy
                    q.push(adj);            // push nto the queue
                    
                }
                 
                map[curr] -> neighbors.push_back(map[adj]); // in current node push adjcant node
            }
        }
        
        return first;
    }
};