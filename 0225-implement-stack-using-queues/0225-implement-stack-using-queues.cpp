class MyStack {
private:
    queue<int> qu0;
    queue<int> qu1;
    int cur;

public:

    MyStack() {
        cur = 0;
    }
    
    void push(int x) {
        if(!cur)    qu0.push(x);
        else    qu1.push(x);
    }
    
    int pop() {
        if(!cur){
            while(qu0.size()>1){
                qu1.push(qu0.front());
                qu0.pop();
            }

            int x = qu0.front();
            qu0.pop();
            cur = 1;
            return x;
        }else{
            while(qu1.size()>1){
                qu0.push(qu1.front());
                qu1.pop();
            }
            int x = qu1.front();
            qu1.pop();
            cur = 0;
            return x;
        }
    }
    
    int top() {
        if(!cur){
            return qu0.back();
        }else{
            return qu1.back();
        }
    }
    
    bool empty() {
        if(!cur)    return (qu0.size()==0)? true: false;
        else    return (qu1.size()==0)? true: false;
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