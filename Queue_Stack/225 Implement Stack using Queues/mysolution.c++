class MyStack {
public:

    queue<int> output;
    MyStack() {
        
    }
    
    void push(int x) {
        output.push(x);
    }
    
    int pop() {
        int n;
        for(int i = 0; i < output.size() ; i++)
        {
            n = output.front();
            if(i != output.size()-1)
                output.push(n);
            output.pop();
        }
        return n;
    }
    
    int top() {
        int n;
        for(int i = 0; i < output.size() ; i++)
        {
            n = output.front();
            output.push(n);
            output.pop();
        }
        return n;
    }
    
    bool empty() {
        return output.empty();
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
