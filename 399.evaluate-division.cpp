/*
 * @lc app=leetcode id=399 lang=cpp
 *
 * [399] Evaluate Division
 */

// @lc code=start
class Solution
{
public:
    /**
 * E is the edge size in graph, V is the vertex num in graph, N is the query size
 * Time: O(E+V*N), Space: O(V)
 * 解題流程: 此題根據input為edge以及其edge上的數值, 因為允許倒過來則value會倒數, 因此首先可以建立一個undiredted graph
 * 此題因為要找到edge上的weighting, 因此可利用unordered_map<string, unordered_map<string, double>>
 * 這樣的形式, key為此node, 而value中的string adj_node, 而其adj_node所對應的value就是此node到adj_node的value
 * 有了這樣的關係之後我們利用DFS
 * 因為為undirected graph, 因此假設此graph為一個connected component, 也就是任一個點都可以到另一點
 * 那麼首先只要先判斷, query的start_node and end_node有沒有在graph中, 沒有則直接push_back -1
 * 有則要找出start_node to end_node的"path cost"
 * 在DFS中base case就是當input的start_node 跟end_node在同一條edge上, 則直接return 這條edge上的數值就好
 * ex: 1 ----- 2 括號代表path cost 
 *        (2)
 * 則直接return 2
 * 若找不到則繼續DFS下去
 * ex: 1----2----3----4
 * 假設start為1, end為4,
 * 第一層DFS會先變成 start:2, end: 4
 * 第二層DFS會變成: start: 3, end: 4
 * 此時已經可以找到start:3, end:4的path cost因此將其return 
 * 第一層接到start:3, end:4的path cost後設為t, 並將其和start:2, end:3的cost相乘再return 
 * 
 */

    double DFS(unordered_map<string, unordered_map<string, double>> &graph, unordered_set<string> &visited, string start, string end)
    {
        // 當start_node and end_node相等則return 1
        if (start == end)
            return 1.0;

        // 代表在同一條edge上, 可以直接找到其weighting時, 則直接return此weighting
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
        // 因為edge上有weighting, 因此value中的unordered_map->string為adj node, double為這個edge上的weighting
        unordered_map<string, unordered_map<string, double>> graph;

        // Build the undirected graph with weighting on edge O(E)
        for (int i = 0; i < equations.size(); i++)
        {
            string start = equations[i][0];
            string end = equations[i][1];
            double value = values[i];
            double inverse_value = 1.0 / value;

            // 建立undiredted graph
            graph[start][end] = value;
            graph[end][start] = inverse_value;
        }

        vector<double> output;
        // O(N * V)
        for (auto v : queries)
        {
            // 為了去紀錄此string是否有被visited過
            unordered_set<string> visited;

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
