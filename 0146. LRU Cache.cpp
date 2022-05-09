class LRUCache {
public:
    class node{
        public:
        int key,val;
        node* prev;
        node* next;
        
        node(int key,int val){
            this->key=key;
            this->val=val;
        }
    };
    
    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);
    
    int cap;
    //key -> address
    unordered_map<int,node*> map;
    
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    void insert(node* curr){
        
        curr->next = head->next;
        curr->prev=head;
        
        head->next->prev=curr;
        head->next=curr;
        
        map[curr->key]=curr;
    }
    
    void remove(node* curr){
        map.erase(curr->key);
        
        curr->next->prev = curr->prev;
        curr->prev->next = curr->next;
    }
    
    int get(int key) {
        if(map.find(key) != map.end()){
            node* curr= map[key];
            
            remove(curr);
            insert(curr);
            return curr->val;
        }
        else {
            return -1;
        }
        
    }
    
    void put(int key, int value) {
        
        if(map.find(key) != map.end()){
            remove(map[key]);
        }
        
        if(map.size()==cap){
            remove(tail->prev);
        }
        
        node* curr = new node(key,value);
        insert(curr);
        
    }
};
