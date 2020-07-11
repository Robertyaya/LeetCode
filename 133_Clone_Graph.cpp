#include <bits/stdc++.h>
using namespace std;
/**
 * DFS version
 * Time: O(N), Space: O(N)
 * 解題流程: DFS為traverse其neighbor node, 過程中如果尚未clone過的則進去DFS進去下去, 直到所有的node都已經被clone過後才會結束DFS的recursvie, 接著開始push_back neighbor
 * 所以BFS為取出一個node, 將這個node clone後, 並將其neieghbor都push完
 * DFS為Search完所有node, 都clone過後, 才開始跑negihbor node push_back
 * 
 */
void DFS(Node *node, unordered_map<Node *, Node *> &map)
{
  for (auto iteratornode : node->neighbors)
  {
    // 代表此node尚未DFS過
    if (!map.count(iteratornode))
    {
      map[iteratornode] = new Node(iteratornode->val);
      DFS(iteratornode, map);
      map[node]->neighbors.push_back(map[iteratornode]);
    }
  }
}
Node *cloneGraph(Node *node)
{
  if (!node)
    return nullptr;

  Node *newGraph = new Node(node->val);
  unordered_map<Node *, Node *> map;
  map[node] = newGraph;
  DFS(node, map);
  return newGraph;
}
/**
 * N is the total node in the graph
 * Time: O(N), Space: O(N)
 * 解題流程: 此法利用BFS
 * 其中關鍵在於map的建立 original_node 為原本的node, map[original_node]所對應的node代表是original_node clone過的node
 * que裡面存的是original node
 * 每次pop出來, traverse其neighbord node, 如果neighbor在map裡面找不到, 代表尚未clone過
 * 因此map[iternode] = new Node 這行代表clone iternode的意思
 * 接著再把negithbor push 到que裡面為了要下次繼續做BFS
 * 
 * map[original]->neighbors.push_back(map[iternode]);
 * 這行代表說map[original]->neightbor這個clone original的node, 的neightbord node
 * map[iternode]代表clone iternode的這個node, 將複製的這個node, 塞到複製的neightbor vector裡面
 * 
 */
Node *cloneGraph(Node *node)
{
  if (!node)
    return nullptr;

  // 建立原本的以及clone的之間映射
  unordered_map<Node *, Node *> map;

  Node *newGraph = new Node(node->val);
  queue<Node *> que;
  que.push(node);
  map[node] = newGraph;
  while (!que.empty())
  {
    // 取出即將被clone的
    Node *original = que.front();
    que.pop();
    // Traverse its neighbor node
    for (auto iternode : original->neighbors)
    {
      // 如果他的neighbor node 尚未出現在map裡面, 則代表尚未被clone過
      if (!map.count(iternode))
      {
        // iternode是原本的node, map[iternode]代表的是新的node
        map[iternode] = new Node(iternode->val);
        que.push(iternode);
      }
      map[original]->neighbors.push_back(map[iternode]);
    }
  }
  return newGraph;
}
