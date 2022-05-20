class MyQueue {
public:
    
    stack<int> res;
    stack<int> temp;
    
    MyQueue() {
        
    }
    
    void push(int x) {
        
        while(res.size()>0){
            temp.push(res.top());
            res.pop();
        }
        
        temp.push(x);
        
        while(temp.size()>0){
            res.push(temp.top());
            temp.pop();
        }
    }
    
    int pop() {
        int a=res.top();
        res.pop();
        return a;
    }
    
    int peek() {
        
        return res.top();
        
    }
    
    bool empty() {
        return res.size()>0 ? false :true;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */