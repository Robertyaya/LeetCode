void DFS(vector<list<int>> &graph, vector<int> &res, int start_node, vector<bool> &visited, string labels, int search_node)
{
  visited[start_node] = true;

  if (labels[start_node] == labels[search_node])
    res[search_node]++;
  else // 不用繼續DFS下去
    return;

  // Traverse its adj node
  for (auto v : graph[start_node])
  {
    int adj_node = v;
    if (!visited[adj_node])
    {
      DFS(graph, res, adj_node, visited, labels, search_node)
    }
  }
}
vector<int> countSubTrees(int n, vector<vector<int>> &edges, string labels)
{
  // Build the undiredted graph first
  vector<list<int>> graph;
  graph.resize(n);
  for (auto v : edges)
  {
    graph[v[0]].push_back(v[1]);
    graph[v[1]].push_back(v[0]);
  }

  // DFS
  vector<int> res;
  res.resize(n);

  for (int i = 0; i < n; i++)
  {
    vector<bool> visited;
    visited.resize(n);
    for (int j = 0; j < i; j++)
      visited[j] = true;

    DFS(graph, res, 0, visited, labels, i);
    visited
  }

  return res;
}
