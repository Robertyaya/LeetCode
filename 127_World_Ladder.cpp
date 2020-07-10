#include <bits/stdc++.h>
using namespace std;
// beginWord = "hit",
// endWord = "cog",
// wordList = ["hot","dot","dog","lot","log","cog"]

// Output: 5

// Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
// return its length 5.
int ladderLengthRecursive(string begin, string end, vector<string> map, int min_path)
{
}
int ladderLength(string beginWord, string endWord, vector<string> &wordList)
{
    return ladderLengthRecursive(beginWord, endWord, wordList, 0);
}