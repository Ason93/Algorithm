#include "questions.h"

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        A_.emplace(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int top = peek();
        B_.pop();
        return top;
    }

    /** Get the front element. */
    int peek() {
        if (B_.empty()) {
            while (!A_.empty()) {
                B_.emplace(A_.top());
                A_.pop();
            }
        }
        return B_.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return A_.empty() && B_.empty();
    }
private:
    stack<int> A_, B_;
};

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        Q_.emplace(x);
        for (int i = 0; i < Q_.size() - 1; i++) {
            Q_.emplace(Q_.front());
            Q_.pop();
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int top = Q_.front();
        Q_.pop();
        return top;
    }

    /** Get the top element. */
    int top() {
        return Q_.front();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return Q_.empty();
    }
private:
    queue<int> Q_;
};

int UseQueueOrStack() {

    cout << "*************** 232. Implement Queue using Stacks ***************" << endl;
    MyQueue q;
    q.push(1);
    q.push(2);
    cout << q.peek() << endl;  // returns 1
    cout << q.pop() << endl;   // returns 1
    cout << q.empty() << endl; // returns false

    cout << "*************** 225. Implement Stack using Queues ***************" << endl;
    MyStack s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << s.pop() << endl;   // returns 1
    cout << s.empty() << endl; // returns false

    return 0;
}