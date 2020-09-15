/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

// @lc code=start
class MinStack
{
    /**
     * 
     * 解題流程: 關鍵在於如何return min
     * 利用一個min數值紀錄目前的min值
     * 在push function中, 每次如果現在要push進去的value比現在的min還小, 先push 現在的min進去再push比較小的value進去
     * 這樣可以保持, 可以記錄上一個最小的min值
     * 如果是比min還要大的, 就不管直接push進去就好, 也直接pop出來就好, 不會影響到stack的min值
     * 
     */
public:
    /** initialize your data structure here. */
    MinStack()
    {
        min = INT_MAX;
    }

    void push(int x)
    {
        if (x <= min)
        {
            sta.push(min);
            min = x;
        }
        sta.push(x);
    }

    void pop()
    {
        // 代表現在的min被pop出來, 需要重新update
        if (sta.top() == min)
        {
            sta.pop();
            min = sta.top();
        }
        sta.pop();
    }

    int top()
    {
        return sta.top();
    }

    int getMin()
    {
        return min;
    }

private:
    stack<int> sta;
    int min;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end
