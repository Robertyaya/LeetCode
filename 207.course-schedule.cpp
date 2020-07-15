/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */

// @lc code=start
class Solution
{
public:
    /**
 * DFS version
 * Time: O(V+E), Space: O(V+E)
 * 解題流程: 此題概念就是一定要是DAG圖(Directed acyclic graph)->無cycle的有向圖
 * 利用做DFS的過程中去檢測cycle, 那檢測cycle的方式就是在對graph做DFS時, 如果今天正在DFS nodeA的adj, 但在DFS nodeA的過程中(還沒結束), 又遇到nodeA了, 那就代表在此graph有cycle
 * 因此我們將visit分成3種狀態, 尚未visit, 正在visit, 以及已經visit完
 * 所謂已經visit完就是當已經traverse的adj做DFS並都沒有碰到自己則將此node標成visit完
 */
    bool DFSUtil(vector<list<int>> &graph, vector<int> &visited, int node)
    {
        visited[node] = 0;
        for (auto v : graph[node])
        {
            // 代表有遇到cycle
            if (visited[v] == 0)
                return false;

            // 代表此node尚未visit過
            if (visited[v] != 1)
            {
                if (!DFSUtil(graph, visited, v))
                    return false;
            }
        }
        visited[node] = 1;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        // Build the directed graph
        vector<list<int>> graph;
        graph.resize(numCourses);
        for (auto v : prerequisites)
            graph[v[1]].push_back(v[0]);

        /**
         * -1代表尚未訪問過
         * 0代表正在訪問
         * 1代表已經訪問結束
         */
        vector<int> visited(numCourses, -1);
        for (int i = 0; i < numCourses; i++)
        {
            if (visited[i] != 1)
            {
                if (!DFSUtil(graph, visited, i))
                    return false;
            }
        }
        return true;
    }
    /**
 * BFS version
 * V代表vertex數量, 也就是numCourses, E代表edge數量, 也就是prerequisited這邊給的關係
 * Time: O(V+E), Space: O(V+E) (建立graph的space)
 * 
 * ex: [1, 0] 代表要學1之前要先學過0, 因此0為基礎, 1為進階
 * 建立成directed graph為 0->1
 * indegree代表的是那個node有多少個node進入
 * ex: 以上面例子, 0的indegree為0, 1的indgree為1(有1個node進入)
 * 而indegree為0代表此node為基礎課程
 * 
 */
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        // Build the directed graph
        vector<list<int>> graph;
        vector<int> indegree;
        graph.resize(numCourses);
        indegree.resize(numCourses);
        // O(E)
        for (int i = 0; i < prerequisites.size(); i++)
        {
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
            // 紀錄每一個node的indegree數值
            indegree[prerequisites[i][0]]++;
        }
        // 從indegree=0的node代表不用基礎就可以學習的課程, 因此可以直接學習
        queue<int> q;
        // O(V)
        for (int i = 0; i < numCourses; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }
        // O(V)
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            // Traverse its adj node
            for (auto v : graph[node])
            {
                // 上面已經將indegree為0的pop出來, 概念就是此課程已經學習掉的意思
                // 現在traverse its adjcent list, 代表進入下一階段課程
                indegree[v]--;
                if (indegree[v] == 0)
                    q.push(v);
            }
        }
        // O(V)
        for (auto v : indegree)
        {
            // 不等於0有兩種情況
            // 1. 代表有cycle
            // 2. 代表有不止一個conected component
            if (v != 0)
                return false;
        }
        return true;
    }
};
// @lc code=end
