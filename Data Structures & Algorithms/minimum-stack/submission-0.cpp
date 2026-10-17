class MinStack {
public:
    stack<int> a;
    stack<int> minstack;
    MinStack() {
    }
    
    void push(int val) {
        a.push(val);
        if(minstack.empty()){
            minstack.push(val);
        }
        else{
            val=(val<minstack.top())?val:minstack.top();
            minstack.push(val);
        }

    }
    
    void pop() {
        a.pop();
        minstack.pop();
    }
    
    int top() {
        return(a.top());
    }
    
    int getMin() {
        return(minstack.top());
    }
};
