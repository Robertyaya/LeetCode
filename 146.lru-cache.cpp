/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */

// @lc code=start

// Use hash linked list
class LRUCache
{
public:
    LRUCache(int capacity)
    {
        size = capacity;
    }

    int get(int key)
    {
        // 並沒有在cache中
        if (!m.count(key))
            return -1;

        // 將key所對應的list node, 搬到cache的最前面位置
        l.splice(l.begin(), l, m[key]);
        return m[key]->second;
    }

    void put(int key, int value)
    {
        auto v = m.find(key);
        // 先刪除已經在list中的, 因為value可能不一樣要update
        if (v != m.end())
        {
            l.erase(m[key]);
        }

        // Need to erase the lase value
        if (l.size() >= size)
        {
            int key = l.rbegin()->first;
            m.erase(key);
            l.pop_back();
        }
        // Push 新的value到最前面
        l.push_front({key, value});
        m[key] = l.begin();
    }

private:
    int size;

    // value is 所對應到的list node, 為了要快速操作list node
    unordered_map<int, list<pair<int, int>>::iterator> m;

    // 因為要做搬移到前面的動作, 利用list可以O(1)
    std::list<pair<int, int>> l;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
