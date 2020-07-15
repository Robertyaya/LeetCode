## Sorting
### Quick Sort
利用Divide-and-Conquer
Time: O(NlogN)
````c++
// Partition為Quick sort最重要的部分
// 目的是根據pivot大小, 將array分成小於pivot, pivot, 大於pivot 這3個部分
int Partition(InputArray, front, end)
{
  // 隨便取, 取end為了迭代方便
  int pivot = InputArray[end]

  // i, 一直指向小於pivot數值的最後一個
  int i = front-1;
  for j = front ~ end 
  {
    // 此時代表小於pivot的數組要加一
    if(InputArray[j] < pivot)
    {
      // 小於pivot的數組++
      i++;
      // 將此時j換到之前那個前面
      swap(InputArray[i], InputArray[j])
    }
  }
  // 將最後面當成pivot的數值交換過來
  i++
  swap(InputArray[i], InputArray[end])
  return i
}
void QuickSort(InputArray, int front, int end)
{
  if(front < end)
  {
    // 此處回傳的是pivot的index, 並且在Partition這個function中我們已將小於pivot的放在左邊, 大於pivot放在右邊
    int pivot = Partition(InputArray, front, end)
    QuickSort(InputArray, front, pivot-1)
    QuickSort(InputArray, pivot+1, end)
  }

}
````
### Merge Sort
也是Divide-and-Conquer的問題
Time: O(NlogN)
````c++
void Merge(InputArray, int front, int mid, int end)
{
  // 將array[front]~array[mid]放到leftsub裡面
  vector<int> leftsub(InputArray.begin()+front, InputArray.begin()+mid+1);
  // 將array[mid+1]~array[right]放到rightsub裡面
  vector<int> rightsub(InputArray.begin()+mid+1, InputArray.begin()+end+1);

  // 在尾端加入max元素
  leftsub.insert(leftsub.end(), INT_MAX)
  rightsub.insert(right.end(), INT_MAX)

  // Start to merge
  int left_index = 0;
  int right_index = 0;
  for(int i=front;i<=end;i++)
  {
    if(leftsub[left_index]<=rightsub[right_index])
    {
      InputArray[i] = leftsub[left_index]
      left_index++
    }
    else
    {
      InputArray[i] = rightsub[right_index]
      right_index++
    }
  }
}
void MergeSort(InputArray, int front, int end)
{
  if(front >= end)
    return;

  int mid = front + (end-front)/2;
  MergeSort(InputArray, front, mid)
  MergeSort(InputArray, mid+1, front)
  Merge(array, front, mid, end)
}
````
## Graph
可參考這系列Graph文章
[Graph intro](http://alrightchiu.github.io/SecondRound/graph-introjian-jie.html)

### BFS
做完一次BFS可產生start_node到任何一個node ``shortest path``
並利用Predecessor可以back tracking回去找出這條路徑確切的軌跡
````c++
class Graph
{
  int V // total node
  vector<list<int>> adj // adjacency lists
}
void BFS(int start_node)
{
  // 紀錄某一點是否已經被拜訪過
  vector<bool> visited(V, false);
  // 紀錄某一點與起點之間"最短距離", 因此初始為最大值
  vector<int> distance(V,INT_MAX); 
  // 紀錄某一點是由哪個點找到的, 以便可以回朔路徑
  vector<int> predecessor(V, -1);

  // 因為要做BFS, 因此需要queue來輔助我們traverse
  queue<int> que;

  int i = start_node;
  // 最外層for迴圈目的是如果此graph不只一個connected component, 也就是只做一次BFS沒辦法traverse到所有的node, 則將i set to j, 當成不同的start_node來做的概念
  for(int j = 0; j < V; j++)
  {
    if(!visited[i])
    {
      visited[i] = true; // 標記現在start_node已經visited過
      distance[i] = 0; // 和起點距離為0
      predecessor[i] = 1;  // start node沒有predecessor, 因此設為-1
      q.push(i);
      while(!que.empty())
      {
        int current_node = que.front();
        que.pop();

        // Print value
        cout << current_node->val << endl;
        
        // Traverse current node's adjacent list
        for(list<int>::iterator iter = adj[current_node].begin(); 
              iter!=adj[current_node].end(); iter++)
        {
          // 尚未visit過的node將其加入queue中
          if(!visited[*iter])
          {
            // 將其標記為visit過
            visited[*iter] = true;
            // 距離為前一點距離+1
            distance[*iter] = distance[current_node] + 1;
            // 更新被找到vertex的predecessor
            predecessor[*iter] = current_node;

            que.push(*iter);
          }
        } 
      }
      // 設成其他的start_node
      i = j;
    }
  }
}
````
### DFS
一樣會求得start_node到任何一個node的一條path, 但是這條path不一定是shortest path
DFS相關應用參考上面連接
利用discover and finish 
ex: 
1. 判斷是否有環
2. Topological Sort
3. Find Strongly Connected Component(SCC) in directed graph

````c++
class Graph
{
  int V // total node
  vector<list<int>> adj // adjacency lists
}
void DFS(int start_node)
{
  vector<bool> visited(V, false); // 紀錄那個node是否有被visit過
  vector<int> discover(V, 0); // 每一個node會去紀錄其dicover time 以及 finish time
  vector<int> finish(V,0); 
  vector<int> predecessor(V,-1); // 這個和BFS一樣, 紀錄上一個node
  int time = 0;

  int i = start_node
  // 避免graph中不只一個connected_component, 這樣的話只做一次DFS沒辦法traverse到所有的node
  for(int j=0; j < V; j++)
  {
    if(!visited[i])
    {
      DFSUtil(start_node, visited, discover, finish, predecessor, time); 
    }
    // 避免做完一次DFS沒有traverse完所有的node
    i = j;
  }
}

void DFSUtil(int current_node, vector<bool>& visited, vector<int>& discover, vector<int>& finish,
              vector<int>& predecessor, int time)
{
  // Print value
  cout << current_node << endl;

  discover[current_node] = ++time; // Update discover time
  visited[current_node] = true; // 標記此node已經拜訪過

  // Traverse current_node's adjacent node
  for(list<int>::iterator iter = adj[current_node].begin();iter!=adj[current_node].end();iter++)
  {
    if(!visited[*iter])
    {
      predecessor[*iter] = current_node;
      DFSUtil(*iter*, visited, discover, finish, predecessor, time); 
    }
  }
  finish[current_node] = ++time; // Update finish time
}
````
