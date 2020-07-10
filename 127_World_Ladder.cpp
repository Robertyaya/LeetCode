#include <bits/stdc++.h>
using namespace std;
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
int ladderLength(string beginWord, string endWord, vector<string> &wordList)
{
    // Build the map, use this to check whether the string in the wordlist
    unordered_set<string> set;
    for (auto v : wordList)
        set.insert(v);

    // 先確認endWord有在wordlist當中, 沒有的話則連找都不用找直接return 0
    if (!set.count(endWord))
        return 0;

    // 用來記錄目前這個string是從beginword走了幾步路過來的
    unordered_map<string, int> map;
    map[beginWord] = 1;

    queue<string> que;
    que.push(beginWord);
    while (!que.empty())
    {
        string NewWord = que.front();
        que.pop();
        // Traverse 每一個字元, 並每一個字元以a~z替換, 看是否存在於set中, 若存在代表此路徑有可能, 則記錄下來
        for (int i = 0; i < NewWord.size(); i++)
        {
            string newword = NewWord;
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                // 跳過自己
                if (newword[i] == ch)
                    continue;
                newword[i] = ch;
                // 最上面已經判斷過endword不在set當中的情況, 因此此處只要找到代表一定存在於set中, 直接return
                if (newword == endWord)
                    return map[NewWord] + 1;

                // 有出現在wordlist中, 但尚未到達過這個string
                if (set.count(newword) && !map.count(newword))
                {
                    que.push(newword);
                    map[newword] = map[NewWord] + 1;
                }
            }
        }
    }
    return 0;
}
