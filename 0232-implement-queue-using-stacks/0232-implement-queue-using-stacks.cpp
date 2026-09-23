class MyQueue {
public:

    stack<int> s1;
    stack<int> s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        while(s1.size() > 1){
            int t = s1.top();
            s2.push(t);
            s1.pop();
        }
        int top = s1.top();
        s1.pop();
        while(!s2.empty()){
            int t = s2.top();
            s1.push(t);
            s2.pop();
        }
        return top;
    }
    
    int peek() {
        while(s1.size() > 1){
            int t = s1.top();
            s2.push(t);
            s1.pop();
        }
        int top = s1.top();
        while(!s2.empty()){
            int t = s2.top();
            s1.push(t);
            s2.pop();
        }
        return top;
    }
    
    bool empty() {
        if(s1.size() == 0){
            return true;
        }else{
            return false;
        }
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