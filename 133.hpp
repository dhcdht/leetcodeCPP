// https://leetcode.com/problems/implement-stack-using-queues/description/
// 225. Implement Stack using Queues
/*
Implement the following operations of a stack using queues.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
empty() -- Return whether the stack is empty.
Example:

MyStack stack = new MyStack();

stack.push(1);
stack.push(2);
stack.top();   // returns 2
stack.pop();   // returns 2
stack.empty(); // returns false
Notes:

You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).
 */
#import <iostream>
#import <queue>

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        m_curQueue = new std::queue<int>();
    }

    /** Push element x onto stack. */
    void push(int x) {
        m_curQueue->push(x);
        m_top = x;
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        std::queue<int> *tempQueue = new std::queue<int>();
        int size = m_curQueue->size();
        for (int i = 0; i < size - 1; ++i) {
            m_top = m_curQueue->front();
            tempQueue->push(m_top);
            m_curQueue->pop();
        }

        int pop = m_curQueue->front();

        delete m_curQueue;
        m_curQueue = tempQueue;

        return pop;
    }

    /** Get the top element. */
    int top() {
        return m_top;
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return m_curQueue->empty();
    }

private:
    std::queue<int> *m_curQueue;
    int m_top;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */
