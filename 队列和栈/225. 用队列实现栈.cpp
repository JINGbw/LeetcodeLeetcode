class MyStack {
public:
    
    
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        //压入的时候，用一个队列暂时存储之前的栈，另一个队列pop空，先压入新元素，再把暂时存储之前的栈的队列再一次push进队列中。
        //如果按压入的顺序存放的话，队列的头会是栈的栈底，但是这里通过调换了，使得q2中存放的顺序（队列的头，就是栈的栈顶）
        
        //先把队列中的全拿出来，放到另一个队列里。
        while (!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        
        //让新来的放在队列q2的第一个，弹出永远从q2弹出
        q2.push(x);
        //再把临时存放的放回q2中  (q1又变为空)
        while (!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        return ;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        //把q2的顺序就是弹出的顺序
        int tmp = q2.front();
        q2.pop();
        return tmp;
        
    }
    
    /** Get the top element. */
    int top() {
        return q2.front();//
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q2.empty();//q1起到转换的作用，不存放数字
    }
private:
    queue <int> q1 , q2 ;//永远从q2压入和弹出，q1只是辅助
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
