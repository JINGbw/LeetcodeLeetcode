class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        spush.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    //题目：用栈实现队列
    //思路：使用两个栈，一个压入，一个弹出，如果弹出栈为空，将压入栈的所有元素放入弹出栈中
    int pop() {
        if (spop.empty()){//如果spop为空，将spush中的元素全部转移到spop中
        while(!spush.empty()){
                spop.push(spush.top());
                spush.pop();
            }
            int tmp = spop.top();
            spop.pop();
            return tmp;
        }
        else {
            int tmp = spop.top();
            spop.pop();
            return tmp;
        }
    }
    
    /** Get the front element. */
    int peek() {
        if (spop.empty()){
            while(!spush.empty()){
                spop.push(spush.top());
                spush.pop();
            } 
            return spop.top();
        }
        else { 
            return spop.top();
        }
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return spush.empty()&&spop.empty();//两栈都空才为空 
    }
private:
    stack <int>spush;
    stack <int>spop;
    
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
