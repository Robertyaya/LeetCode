/*
 * @lc app=leetcode id=332 lang=cpp
 *
 * [332] Reconstruct Itinerary
 */

// @lc code=start
class Solution
{
    /**
 * N is the total node
 * Time: O(NlogN), Space: O(N)
 * 解題流程: 此題根據機票要找出整條路線為多少, 首先先建立directed graph, 而題目中說到, 要選order較小的, 因此adj node部分利用multiset, 這樣order小的node就會先traverse到
 * 基本上這題是在考edge的traverse, 每一段路線走過之後就將其刪掉, 直到每一個node裡面的multi為empty(), 代表全部路線都走完了
 * 
 */
public:
    void DFS(unordered_map<string, multiset<string>> &graph, string node, vector<string> &output)
    {
        while (!graph[node].empty())
        {
            // 取出adj node, 因為為multiset, 因此此node為order最小的
            string str = *graph[node].begin();

            // 刪除這條node->str的這條路線
            graph[node].erase(graph[node].begin());

            // 以str為start_node繼續DFS
            DFS(graph, str, output);
        }

        // 當input node的adj node都空的時後, 代表此為旅程的最後一個node, 將其push_back進vector裡面
        output.push_back(node);
    }

    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        // Build the directed graph O(NlogN)
        unordered_map<string, multiset<string>> graph;
        for (auto v : tickets)
        {
            // multiset insert O(logN)
            graph[v[0]].insert(v[1]);
        }

        vector<string> output;
        // O(N), 起點為JFK
        DFS(graph, "JFK", output);

        // O(N) 要reverse, 因為DFS中push_back的順序是從最後面一直到最前面
        vector<string> a(output.rbegin(), output.rend());
        return a;
    }
};
// @lc code=end
