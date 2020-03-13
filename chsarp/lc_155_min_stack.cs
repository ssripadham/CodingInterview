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
public class MinStack {

    /** initialize your data structure here. */
    Stack< KeyValuePair<int, int> > s;
    
    public MinStack() {
        s = new Stack<KeyValuePair<int, int>>();
    }
    
    public void Push(int x) {
        if (s.Count == 0){
            s.Push( new KeyValuePair<int,int>(x,x));
        } else {
            s.Push( new KeyValuePair<int,int> (x, Math.Min(x,s.Peek().Value)));
        }
    }
    
    public void Pop() {
        if (!(s.Count == 0)){
            var elem = s.Pop();
        }
    }
    
    public int Top() {
        if (!(s.Count == 0)){
            return s.Peek().Key;
        }
        return -1;
    }
    
    public int GetMin() {
        if (!(s.Count == 0)){
            return s.Peek().Value;
        }
        return -1;
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.Push(x);
 * obj.Pop();
 * int param_3 = obj.Top();
 * int param_4 = obj.GetMin();
 */