class MinStack {
public:
    stack<int> s;
    stack<int> s2;
    int mini=INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        if(s2.empty()) s2.push(val);
        else{
            s2.push(min(s.top(),s2.top()));
        }
    }
    
    void pop() {
        s2.pop();
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return s2.top();
    }
};
