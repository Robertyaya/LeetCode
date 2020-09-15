/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 */

// @lc code=start
/**
 * wordList size is N, beginWord size is constant, a~z is constant
 * Time: O(N), Space: O(N)
 * 解題流程: 這題利用BFS去找
 * beginWord = "hit",
 * endWord = "cog",
 * wordList = ["hot","dot","dog","lot","log","cog"]
 * hit h從a~z找, i從a~z找, t從a~z找
 * 過程中有在wordlist中的, 代表是一種可能路徑, 像水波一樣一層一層過去
 * hit->hot->一層一層過去直到到達endWord
 *      ait
 *      hid
 * 如果是用DFS思維的話, 就是先一條路走到底
 * BFS思維就是一圈一圈直到終點, 就可以知道最短路徑
 * 因此如果要找最短路徑都適用BFS, 類似迷宮中找路徑
 * 此處每一個轉角都有26種可能要去check, 如果有在wordlist代表此路徑可則加到queue中
 */
class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> set;
        for (auto v : wordList)
            set.insert(v);

        // End word不在wordlist中, 直接return 0
        if (!set.count(endWord))
            return 0;

        // 紀錄走到目前這個string走了多少步
        unordered_map<string, int> map;
        queue<string> que;
        map[beginWord] = 1;
        que.push(beginWord);
        while (!que.empty())
        {
            string str = que.front();
            que.pop();
            // Traverse 每一個字元位置
            for (int i = 0; i < str.size(); i++)
            {
                string temp = str;
                // Traverse a~z在每個字元位置上
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    temp[i] = ch;
                    if (temp == endWord)
                        return map[str] + 1;

                    // 要多判斷一個map.count, 因為如果已經走過的, 就不能再走
                    if (set.count(temp) && !map.count(temp))
                    {
                        que.push(temp);
                        map[temp] = map[str] + 1; // 將新的string insert to map
                    }
                }
            }
        }
        return 0;
    }
};
// @lc code=end
