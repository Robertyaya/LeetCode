/*
 * @lc app=leetcode id=310 lang=cpp
 *
 * [310] Minimum Height Trees
 *
 * https://leetcode.com/problems/minimum-height-trees/description/
 *
 * algorithms
 * Medium (32.10%)
 * Likes:    1869
 * Dislikes: 98
 * Total Accepted:    94.9K
 * Total Submissions: 295.5K
 * Testcase Example:  '4\n[[1,0],[1,2],[1,3]]'
 *
 * For an undirected graph with tree characteristics, we can choose any node as
 * the root. The result graph is then a rooted tree. Among all possible rooted
 * trees, those with minimum height are called minimum height trees (MHTs).
 * Given such a graph, write a function to find all the MHTs and return a list
 * of their root labels.
 * 
 * Format
 * The graph contains n nodes which are labeled from 0 to n - 1. You will be
 * given the number n and a list of undirected edges (each edge is a pair of
 * labels).
 * 
 * You can assume that no duplicate edges will appear in edges. Since all edges
 * are undirected, [0, 1] is the same as [1, 0] and thus will not appear
 * together in edges.
 * 
 * Example 1 :
 * 
 * 
 * Input: n = 4, edges = [[1, 0], [1, 2], [1, 3]]
 * 
 * ⁠       0
 * ⁠       |
 * ⁠       1
 * ⁠      / \
 * ⁠     2   3 
 * 
 * Output: [1]
 * 
 * 
 * Example 2 :
 * 
 * 
 * Input: n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]
 * 
 * ⁠    0  1  2
 * ⁠     \ | /
 * ⁠       3
 * ⁠       |
 * ⁠       4
 * ⁠       |
 * ⁠       5 
 * 
 * Output: [3, 4]
 * 
 * Note:
 * 
 * 
 * According to the definition of tree on Wikipedia: “a tree is an undirected
 * graph in which any two vertices are connected by exactly one path. In other
 * words, any connected graph without simple cycles is a tree.”
 * The height of a rooted tree is the number of edges on the longest downward
 * path between the root and a leaf.
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    /**
 * Time: O(V+E), Space: O(V+E)
 * 解題流程: 此題要找出最小樹高, 因為為undiredted graph, 因此每一個node都可以當成root, 在graph越邊邊的node當root的話, 樹高會越大, 如果要越小, 則是找越中間的, 因為樹高在這邊其實代表的意義就是root為start_node, 到最遠一個node的path即為樹高, 因此為了找出最中間那個樹高, 利用剝洋蔥的概念一層一層往裡面
 * 利用BFS
 * graph[node].size() == 1 代表其adj node只有一個， 因此為最邊邊的那一層, 先將其塞入queue中, 在做BFS過程中, 每次都做一層, 做完一層之後再找出adj node為1的繼續放入queue中, 但要扣掉原本的那個node
 * ex: 1-2-3-4-5
 * 以此例子, 會先1,5塞入queue中, 在做BFS過程中, 2的那個node扣掉原本和1相連也只會剩一個3和其相連, 因此在將2,4放入queue中
 * 最後有個關鍵就是, 最後不是剩下一個就是剩下2個, 因此當此時size<=2時就要break出來
 * ex: 如果有3個 1-2-3
 * 那1跟3當root一定大於2當root, 因此1,3都可以刪掉
 * 2個: 原本可能是1-2-3-4  刪掉1跟4 後剩下2-3, 那2跟3當root其實都相同
 * 這兩個當root數值會相同, 因此兩個都是答案
 * 1個就不用說了就一定是root
 * 
 */
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        if (edges.empty())
            return {0};

        if (edges.size() == 1)
        {
            return {0, 1};
        }

        // Build the undirected graph O(E)
        vector<unordered_set<int>> graph;
        graph.resize(n);
        for (auto v : edges)
        {
            graph[v[0]].insert(v[1]);
            graph[v[1]].insert(v[0]);
        }

        queue<int> que;
        // O(V)
        for (int i = 0; i < graph.size(); i++)
        {
            // 代表只有一個node和其相連, 所代表意義就是最外層的那個
            if (graph[i].size() == 1)
                que.push(i);
        }

        // O(V)
        while (!que.empty())
        {
            int size = que.size();
            n -= size; //為了確定目前剩下多少個node
            for (int i = 0; i < size; i++)
            {
                int node = que.front();
                que.pop();
                for (auto v : graph[node])
                {
                    // 將原本的刪掉
                    graph[v].erase(node);
                    if (graph[v].size() == 1)
                        que.push(v);
                }
            }

            if (n <= 2)
                break;
        }

        vector<int> output;
        while (!que.empty())
        {
            int temp = que.front();
            que.pop();
            output.push_back(temp);
        }
        return output;
    }
};
// @lc code=end
