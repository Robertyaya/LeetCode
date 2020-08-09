/*
 * @lc app=leetcode id=225 lang=cpp
 *
 * [225] Implement Stack using Queues
 */

// @lc code=start
class MyStack
{
    /**
     * 利用兩個queue來模擬stack
     */
public:
    /** Initialize your data structure here. */
    MyStack()
    {
    }

    /** Push element x onto stack. O(1)*/
    void push(int x)
    {
        a.push(x);
    }

    /** Removes the element on top of the stack and returns that element. O(N)*/
    int pop()
    {
        int top;
        while (!a.empty())
        {
            int temp = a.front();
            a.pop();
            if (a.empty())
            {
                top = temp;
                break;
            }
            b.push(temp);
        }
        while (!b.empty())
        {
            int temp = b.front();
            b.pop();
            a.push(temp);
        }
        return top;
    }

    /** Get the top element. O(N)*/
    int top()
    {
        int top;
        while (!a.empty())
        {
            int temp = a.front();
            a.pop();
            if (a.empty())
                top = temp;
            b.push(temp);
        }
        while (!b.empty())
        {
            int temp = b.front();
            b.pop();
            a.push(temp);
        }
        return top;
    }

    /** Returns whether the stack is empty. */
    bool empty()
    {
        return a.empty();
    }

private:
    queue<int> a, b;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end
