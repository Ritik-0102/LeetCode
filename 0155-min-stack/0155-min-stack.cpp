class MinStack {
public:
    // Approach 2 : 
    // In this approach we will make stack in O(n) space complexity only

    stack<long long> s;
    long long minVal;

    MinStack() {
        
    }
    
    void push(int value) {
        if(s.empty()){
            s.push(value);
            minVal = value;
        }
        else{
            if(value < minVal){
                s.push((long long) 2 * value - minVal);
                minVal = value;
            }
            else{
                s.push(value);
            }
        }
    }
    
    void pop() {
        if(s.top() < minVal){
            minVal = 2*minVal - s.top();
        }
        s.pop();
    }
    
    int top() {
        if(s.top() < minVal){
            return minVal;
        }
        return s.top();
    }
    
    int getMin() {
        return minVal;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */