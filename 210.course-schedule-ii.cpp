/*
 * @lc app=leetcode id=210 lang=cpp
 *
 * [210] Course Schedule II
 */

// @lc code=start
class Solution
{
    /**
 * Time: O(V+E+VlogV), Space: O(V+E)
 * 解題流程: 這題就是在做topological sort
 * 利用在DFS過程中, 去紀錄每一點的finish time, finish time最大的代表為第一個node一直到finish time 最小的
 */
public:
    bool DFS(vector<list<int>> &graph, int node, vector<int> &start, vector<int> &finish, vector<int> &visited, int &time)
    {
        // 標記成正在traverse, 因此以下DFS如果又遇到此node, 代表為有cycle
        visited[node] = 0;
        start[node] = ++time;
        for (auto v : graph[node])
        {
            // Have cycle
            if (visited[v] == 0)
                return false;

            if (visited[v] == -1)
            {
                if (!DFS(graph, v, start, finish, visited, time))
                    return false;
            }
        }
        visited[node] = 1;
        finish[node] = ++time;
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        // Build the directed graph O(E)
        vector<list<int>> graph;
        graph.resize(numCourses);
        for (auto v : prerequisites)
            graph[v[1]].push_back(v[0]);

        // 紀錄start and finish time in every node
        vector<int> start(numCourses, 0);
        vector<int> finish(numCourses, 0);
        // 用來檢測是否有cycle
        vector<int> visited(numCourses, -1);
        int time = 0;

        // O(V)
        for (int i = 0; i < numCourses; i++)
        {
            if (visited[i] == -1)
            {
                // 代表有cycle發生, 則直接return
                if (!DFS(graph, i, start, finish, visited, time))
                    return {};
            }
        }
        // pair -> <node, finish_time>
        vector<pair<int, int>> largetosmall;
        largetosmall.resize(numCourses);
        for (int i = 0; i < finish.size(); i++)
        {
            largetosmall[i].first = i;
            largetosmall[i].second = finish[i];
        }
        // 對finish time做排序, 從大到小 O(VlogV)
        sort(largetosmall.begin(), largetosmall.end(), [](auto a, auto b) { return a.second > b.second; });

        // 最大的finish time即為start node
        vector<int> output;
        for (auto v : largetosmall)
        {
            output.push_back(v.first);
        }

        return output;
    }
};
// @lc code=end
