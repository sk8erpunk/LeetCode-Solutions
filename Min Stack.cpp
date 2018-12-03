/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
Example:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.
*/


class MinStack {
private:
    stack<int> min_stack;
    stack<int> my_stack;
    
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        if(my_stack.empty()) {
            my_stack.push(x);
            min_stack.push(x);
            return;
        }
        if(x < min_stack.top()){
            min_stack.push(x);
        } else {
            min_stack.push(min_stack.top());
        }
        my_stack.push(x);
    }
    
    void pop() {
        my_stack.pop();
        min_stack.pop();
    }
    int top() {
        return my_stack.top();
    }
    
    int getMin() {
        if(my_stack.empty()){
            throw -1;
        }
        return min_stack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */