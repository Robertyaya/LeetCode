/*
 * @lc app=leetcode id=341 lang=cpp
 *
 * [341] Flatten Nested List Iterator
 */

// @lc code=start
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator
{
public:
    NestedIterator(vector<NestedInteger> &nestedList)
    {
        // Traverse 所有element, 如果是integer, 則直接放入vector, 如果不是則recursive繼續下去traverse
        for (int i = 0; i < nestedList.size(); i++)
        {
            if (nestedList[i].isInteger())
                que.push(nestedList[i].getInteger());
            else
            {
                Help(nestedList[i].getList(), que);
            }
        }
    }

    void Help(const vector<NestedInteger> &nestedList, queue<int> &que)
    {
        for (int i = 0; i < nestedList.size(); i++)
        {
            if (nestedList[i].isInteger())
                que.push(nestedList[i].getInteger());
            else
                Help(nestedList[i].getList(), que);
        }
    }

    int next()
    {
        int value = que.front();
        que.pop();
        return value;
    }

    bool hasNext()
    {
        return !que.empty();
    }

private:
    queue<int> que;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
// @lc code=end
