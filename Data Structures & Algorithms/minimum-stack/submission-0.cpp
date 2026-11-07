class MinStack {
public:
    stack<int> st,minStack;
    MinStack() {
    }
    
    void push(int val) {
        if(minStack.empty()){
            minStack.push(val);
        }
        else if(val<=minStack.top()){
            minStack.push(val);
        }
        st.push(val);
    }
    
    void pop() {
        int poppingValue = st.top();
        if(poppingValue<=minStack.top()){
            minStack.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
