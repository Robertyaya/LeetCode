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
### BFS
````c++
class Graph
{
  int V // total node
  vector<vector<int>> adj // adjacency lists
}
void BFS(int start_node)
{
  // Record which node has already visited. Initial as false, and the size the No. of node
  vector<bool> visited(V, false);

  // 因為要做BFS, 因此需要queue來輔助我們traverse
  queue<int> que;

  // Mark the current node as visited and enqueue it
  visited[start_node] = true;
  que.push(start_node);
  while(!que.empty())
  {
    int current_node = que.front();
    que.pop();

    // Print value
    cout << current_node->val << endl;
    
    // Traverse current node's adjacent list
    for(int i=0; i<adj[current_node].size(); i++)
    {
      int adj_node = adj[current_node][i];
      // 尚未visit過的node將其加入queue中
      if(!visited[adj_node])
      {
        // 將其標記為visit過
        visited[adj_node] = true;
        que.push(adj_node);
      }
    } 
  }
}
````
### DFS
````c++
class Graph
{
  int V // total node
  vector<vector<int>> adj // adjacency lists
}
void DFS(int start_node)
{
  // Record which node has already visited. Initial as false, and the size the No. of node
  vector<bool> visited(V, false);

  // Call the recursive helper function to print DFS traversal
  DFSUtil(start_node, visited)
}

void DFSUtil(int node, vector<bool>& visited)
{
  visited[node] = true
  // Print value
  cout << node << endl;

  for(int i=0; i<adj[current_node].size(); i++)
  {
    int adj_node = adj[current_node][i];
    if(!visited[adj_node])
      DFSUtil(adj_node, visited)
  }
}
````
