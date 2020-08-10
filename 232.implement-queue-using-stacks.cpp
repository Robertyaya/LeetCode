/*
 * @lc app=leetcode id=232 lang=cpp
 *
 * [232] Implement Queue using Stacks
 */

// @lc code=start
class MyQueue
{
public:
    /** Initialize your data structure here. */
    MyQueue()
    {
    }

    /** Push element x to the back of queue.O(N)*/
    void push(int x)
    {
        while (!a.empty())
        {
            int top = a.top();
            a.pop();
            b.push(top);
        }
        a.push(x);
        while (!b.empty())
        {
            int top = b.top();
            b.pop();
            a.push(top);
        }
    }

    /** Removes the element from in front of queue and returns that element. O(1) */
    int pop()
    {
        int temp = a.top();
        a.pop();
        return temp;
    }

    /** Get the front element.O(1) */
    int peek()
    {
        return a.top();
    }

    /** Returns whether the queue is empty. */
    bool empty()
    {
        return a.empty();
    }

private:
    stack<int> a, b;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end
