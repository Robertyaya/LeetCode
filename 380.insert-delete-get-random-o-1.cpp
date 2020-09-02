/*
 * @lc app=leetcode id=380 lang=cpp
 *
 * [380] Insert Delete GetRandom O(1)
 */

// @lc code=start
class RandomizedSet
{
public:
    /** Initialize your data structure here. */
    RandomizedSet()
    {
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val)
    {
        if (!map.count(val))
        {
            vec.push_back(val);
            map[val] = vec.size() - 1;
            return true;
        }
        else
            return false;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    // 關鍵在於在remove中如何達到O(1), 因為map中有紀錄val所對應的vector index
    // 將要刪除的target val和最後一個數字swap, 記得map中原本最後一個數字的index要改成刪除的那個index
    // 在pop_back即可使remove在O(1)完成
    bool remove(int val)
    {
        if (map.count(val))
        {
            int index = map[val];
            swap(vec[index], vec[vec.size() - 1]);
            map[vec[index]] = index;
            vec.pop_back();
            map.erase(val);
            return true;
        }
        else
            return false;
    }

    /** Get a random element from the set. */
    int getRandom()
    {
        int index = rand() % vec.size();
        return vec[index];
    }

private:
    // key為val, value為vector中的index
    unordered_map<int, int> map;
    vector<int> vec;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end
