class MyQueue {
public:

    stack<int> temp;
    stack<int> target;

    MyQueue() {

    }
    void push(int x) {
        while(!target.empty())
        {
            temp.push(target.top());
            target.pop();
        }
        target.push(x);
        while(!temp.empty())
        {
            target.push(temp.top());
            temp.pop();
        }
    }
    
    int pop() {
        int front = target.top();
        target.pop();
        return front;
    }
    
    int peek() {
        return target.top();
    }
    
    bool empty() {
        return target.empty();
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
