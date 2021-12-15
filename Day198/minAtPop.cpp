#define ll long 
class MinStack {
    stack<ll> st;
    int min;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty())
        {
            st.push(val);
            min = val;
        }
        else if(val>=min)
        {
            st.push(val);
        }
        else
        {
            st.push(2*(ll)val - min);
            min = val;
        }
    }
    
    void pop() {
        if(st.top()>=min)st.pop();
        else 
        {
            min = 2*(ll)min - st.top();
            st.pop();
        }
    }
    
    int top() {
        if(st.top()>=min)
        {
            return st.top();
        }
        else
            return min;
    }
    
    int getMin() {
        return min;
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