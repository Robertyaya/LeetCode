/*
 * @lc app=leetcode id=399 lang=cpp
 *
 * [399] Evaluate Division
 */

// @lc code=start
class Solution
{
public:
    double DFS(unordered_map<string, unordered_map<string, double>> &graph, unordered_set<string> &visited, string start, string end)
    {
        if (start == end)
            return 1.0;

        if (graph[start].count(end))
            return graph[start][end];

        visited.insert(start);
        // Traverse its adj node
        for (auto v : graph[start])
        {
            if (!visited.count(v.first))
            {
                double t = DFS(graph, visited, v.first, end);

                if (t > 0.0)
                    return t * v.second;
            }
        }
        return -1.0;
    }
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        unordered_map<string, unordered_map<string, double>> graph;
        // Build the undirected graph with weighting on edge
        for (int i = 0; i < equations.size(); i++)
        {
            string start = equations[i][0];
            string end = equations[i][1];
            double value = values[i];
            double inverse_value = 1.0 / value;

            graph[start][end] = value;
            graph[end][start] = inverse_value;
        }

        unordered_set<string> visited;
        vector<double> output;
        for (auto v : queries)
        {
            // 不存在於graph中的node, 直接return -1
            if (!graph.count(v[0]) || !graph.count(v[1]))
                output.push_back(-1);
            else
            {
                double answer = DFS(graph, visited, v[0], v[1]);
                output.push_back(answer);
            }
        }
        return output;
    }
};
// @lc code=end
