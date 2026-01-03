class MinStack {
private:
    stack<int> st;
    int topp;

public:
    MinStack() { topp = -1; }

    void push(int val) {
        st.push(val);
        topp++;
    }

    void pop() {
        if (topp == -1 || st.empty()) {
            return ;
        } else {
            st.pop();
        }
    }

    int top() {
        if (!st.empty()) {
            return st.top();
        }
        return -1;
    }

    int getMin() {
        stack<int> minSt = st;
        int minVal = INT_MAX;
        if (minSt.empty()) {
            return minVal;
        }
        while (!minSt.empty()) {
            minVal = min(minVal, minSt.top());
            minSt.pop();
        }
        return minVal;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */