class MyStack {
public:
    deque <int> dq; //using deque
    
    MyStack() {
        
    }
    
    void push(int x) {
        
        dq.push_back(x); 
    }
    
    int pop() {
        
        int y = dq.back();
        dq.pop_back();
        return y;
    }
    
    int top() {
        
        return dq.back();
    }
    
    bool empty() {
        
        return dq.size() == 0;
        
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */