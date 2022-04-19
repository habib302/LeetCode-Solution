/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> map;
    
    Node* copyRandomList(Node* head) {
        
        //base case
        if(head==NULL) return head;
        
        Node* curr=head;
        
        //just create the node
        //also create the map
        while(curr != NULL){
            
            Node *temp=new Node(0);
            temp->val = curr->val;
            map[curr]=temp;
            
            curr=curr->next;
        }
        
        curr=head;
        //Node* curr;
        
        while(curr !=NULL ){
            
            //create a temporary node
            Node *temp = map[curr];
            
            //save the random & next to build the chain
            temp->random = map[curr->random];
            temp->next = map[curr->next];
            
            curr = curr->next;
        }
        
        return map[head];
    }
};