# Array
## Binary Search
[34_Find_First_and_Last_Position_In_SortedArray](34_Find_First_and_Last_Position_In_SortedArray.cpp)  
[374_Guess_Number_Higher_or_Lower](374_Guess_Number_Higher_or_Lower.cpp)
````c++
BinarySearch_Iterative(InputArray, int target)
{
  // The array need to sort
  sort(InputArray);

  int left = 0;
  int right = InputArray.size()-1;

  while(right >= left)
  {
    int mid = left + (right-left)/2;

    // Find the target
    if(mid == target)
      return;
    else if(InputArray[mid] > target)
      right = mid-1;
    else
      left = mid+1;
  }
}
````
````c++
BinarySearch_Recursive(InputArray, int left, int right, int target)
{
  if(left > right)
    return false;
  
  int mid = left + (right-left)/2;
  if(InputArray[mid] == target)
    return true;
  else if(InputArray[mid] > target)
    return BinarySearch_Recursive(InputArray, left, mid-1);
  else
    return BinarySearch_Recursive(InputArray, mid+1, right)

}
BinarySearch(InputArray, int target)
{
  sort(InputArray)

  BinarySearch_Recursive(InputArray, 0, InputArray.size()-1, target)
}
````
### Rotated Sorted Array templete
[33_Search_in_Rotated_Sorted_Array](33_Search_in_Rotated_Sorted_Array.cpp)   
[81_Search_in_Rotated_Sorted_Arrayii](81_Search_in_Rotated_Sorted_Array.cpp)
```c++
Search_Rotated_Array(InputArray, int target)
{
  int left = 0;
  int right = InputArray.size()-1;
  while(right>=left)
  {
    int mid = left+(right-left)/2;

    if(InputArray[mid] == target)
      return;
    // 代表旋轉點在右邊, 而mid左邊為從小到大排好的
    else if(InputArray[mid] > InputArray[right])
    {
      // 左邊的判斷式可以寫出來, 因此判斷是不是在mid的左邊, 如果不滿足則代表是在mid的右邊
      if(InputArray[left] <= target && InputArray[mid] > target)
        right = mid-1;
      else
        left = mid+1;
    }
    // 代表旋轉點在左邊, 而mid右邊為從小到大排好的
    else 
    {
      if(InputArray[right] >= target && InputArray[mid] < target)
        left = mid+1;
      else
        right = mid-1;
    }
    
  }
}
```
### Find Upper bound and Lower bound templete
[34_Find_First_and_Last_Position_In_SortedArray](34_Find_First_and_Last_Position_In_SortedArray.cpp)  
[278_First_Bad_Version](278_First_Bad_Version.cpp)
````c++
SearchRange(InputArray, int target)
{
  int left = 0;
  int right = InputArray.size(); // 這邊要故意超出一個
  int lower_bound, upper_bound;

  // Find lower bound of target value
  while(right > left)
  {
    int mid = left + (right-left)/2;
    if(target > nums[mid])
      left = mid+1;
    else
      right = mid;
  }
  lower_bound = right;

  // The target value not in the InputArray
  if(right == InputArray.size() || nums[right]!=target)
    return false
  
  // Find Uppder bound of target value
  left = 0;
  right =nums.size();
  while(right > left)
  {
    int mid = left + (right-left)/2;
    // 跟上面找lower bound完全一樣, 差別只在於這邊因為要找upper bound, 因此會多一個等號
    if(target >= num[mid])
      left = mid+1;
    else
      right = mid;
  }
  upper_bound = right-1;
}
````
### Find Insert Position templete
[35_Search_Insert_Position](35_Search_Insert_Position.cpp)
````c++
FindInsertPosition(InputArray, int target)
{
  int left = 0;
  int right = InputArray.size()-1;
  
  while(right >= left)
  {
    int mid = left + (right-left)/2;

    // Can find the target in the input array
    if(InputArray[mid] == target)
      return;
    else if(InputArray[mid] > target)
      right = mid-1;
    else
      left = mid+1;
  }

  // Can't find the target in the input array, need to return the position which be inserted
  if(taget > InputArray[mid])
    return mid+1;
  else  
    return mid;
}
````
## Two Sum templete
[1_Two_Sum](1_Two_Sum.cpp)
[653_Input_is_a_BST](653_Input_is_a_BST.cpp)
````c++
TwoSum(input_container, target)
{
  // 利用一個unordered_set紀錄已經tarverse過得value
  unordered_set<type> set

  // Traverse input_container (BST or array)
  // If the BST, use pre-order traverse
  for (auto v: input_container)
  {
    // 計算出和current value 所match的數值
    match_value = target - v
    
    // 到unordered_set中檢查, 如果有則代表前面已經出現過, 因此return true, 沒有則將現在的放到set中
    if(set.count(match_value))
      return true
    set.insert(v)
  }
}
````
## Two pointer templete
[167_Input_Array_is_Sorted](167_Input_Array_is_Sorted.cpp)  
[11_Container_with_Most_Water](11_Container_with_Most_Water.cpp)  
[15_3Sum](15_3Sum.cpp)  
[16_3Sum_Closet](16_3Sum_Closet.cpp)  
[18_4Sum](18_4Sum.cpp)
````c++
TwoPointer(InputArray)
{
  int left = 0;
  int right = InputArray.size()-1;
  
  while(left <= right)
  {
    if(achieve_goal)
      break;
  
    if(some_condition)
      left++;
    else(some_condition)
      right--;
  }
}
````
## Back tracking templete
[39_Combination_Sum](39_Combination_Sum.cpp)  
[40_Combination_Sum_2](40_Combination_Sum_2.cpp)  
[216_Combination_Sum_3](216_Combination_Sum_3.cpp)  
[78_Subsets](78_Subsets.cpp)  
[90_Subsets2](90_Subsets2.cpp)  
[46_Permutations](46_Permutations.cpp)  
[47_Permutations2](47_Permutations2.cpp)  
````c++
BackTracking_Recursive(InputArray, int target, vector<vector<int>>& res, vector<int>& current)
{
  // 代表此時current vector裡面的數字已經加起來和target相同, 因此此路徑可以加到res裡面
  if(target == 0)
  {
    res.push_back(current);
    return;
  }

  /**
   * Back tracking 的關鍵所在, 根據題目要求,
   * 1. 看可不可以重複選數字
   * 2. 是否inputArray會有duplicate num
   * 等等需求去改變start選擇下一條路徑的起始點
   * 想成路徑問題, 下一條路要選哪一個, 而且選的那個數字一定要小於target, 如果已經大於了因為前面已經sorting過, 那後面所有數字就根本不用選了一定不會和target相同
   * 概念上有點像是DFS走迷宮概念, 一條路走到底之後再back track回來換另外一條
   */
  for i (start to end && target >= InputArray[i])
  {
    // 先走這條路徑
    current.push_back(InputArray[i]);
    BackTracking_Recursive(InputArray, target-InputArray[i], res, current);
    // Back回來後pop_back出原本路徑換成另外一條繼續走 
    current.pop_back();
  }
}
BackTracking(InputArray, int target)
{
  // Sorting first
  sort(InputArray.begin(), InputArray.end())

  vector<vector<int>> res;
  vector<int> current
  BackTracking_Recursive(InputArray, target, res, current);
}
````
## Matrix rotate or spiral order templete
[48_Rotate_Image](48_Rotate_Image.cpp)  
[54_Spiral_Matrix](54_Spiral_Matrix.cpp)  
[59_Spiral_Matrix2](59_Spiral_Matrix2.cpp)  
````c++
RotateMatrix(InputMatrix)
{
  int start_index = 0;
  int end_index = InputMatrix.size()-1;
  int level = 0;
  for(end_index > start_index)
  {
    // 分層處理, 一層一層下去
    // do something, base on the start_index, end_index and level

    // update
    start_index++;
    end_index--;
    level++;
  }
}
````
## DFS
[1306_Jump_Game3](1306_Jump_Game3.cpp)  

## Kadane's Algorithm
找出加起來數值最大的區間  
[53_Maximum_Subarray](53_Maximum_Subarray.cpp)  
[55_Jump_Game](55_Jump_Game.cpp)    
[45_Jump_Game2](45_Jump_Game2.cpp)  
````c++
// O(N)
Kadane_Algorithm(InputArray)
{
  // 當下最大的區間
  int max_current = InputArray[0];
  // 走到目前為止最大的區間
  int max_sofar = InputArray[0];

  for(int i=1;i<InputArray.size();i++)
  {
    // 如果current的數值比prefix+current數值還大, 那就沒必要繼續update之前的prefix, 直接替換成current value就好
    max_current = max(max_current+nums[i], nums[i]);
    max_sofar = max(max_current, max_sofar);
  }
  return max_sofar;
}
````
# String
## DFS
[17_Letter_Combinations_of_Phone_Number](17_Letter_Combinations_of_Phone_Number.cpp)  
[22_Generate_Parentheses](22_Generate_Parentheses.cpp)

## Anagram templete
可利用變種的hash map形式, A~Z and a~z的ASCII code都在128以內, 因此可利用這點來做, 若都為小寫字母的話可以更省空間為26個a~z, 但每個都要扣掉'a'的ASCII  
[49_Group_Anagrams](49_Group_Anagrams.cpp)  
[242_Valid_Anagram](242_Valid_Anagram.cpp)  
[438_Find_All_Anagrams_In_String](438_Find_All_Anagrams_In_String.cpp)  
````c++
// The string is long
Anagrams(InputString1, InputString2)
{
  // If the char will not duplicate in string, we can use bool to save
  // If the char will appear duplicate in string, we use int to record how many time it appear
  int map[26] = {0};

  // Build the map
  for(auto v: InputString1)
  {
    // 將其壓縮到0~25
    map[v-'a']++;
  }

  // Check the string
  for(auto v: InputString2)
  {
    map[v-'a']--;

    // Represent not match
    if(map[v-'a'] < 0)
      return false
  }
}

Anagrams_SlidingWindow(InputString, target)
{
  int map[26] = {0}

  // Build the map

  // Sliding window to check
  for(int i=0;i<InputString.size();i++)
  {
    // Add new char
    map[InputString[i]-'a']++;

    // Remove old char
    map[InputString[i-target.size()]-'a']--;

    // Check whether same as target string
  }
}

// The string is short
Anagrams(InputString1, InputString2)
{
  return sort(InputString1) == sort(InputString2);
}
````

## Longest (condition) substring templete
### No repeating char
[3_Longest_Substring_Without_Repeating_Characters](3_Longest_Substring_Without_Repeating_Characters.cpp)  
````c++
LongestNoRepeating(InputString)
{
  // Key is the char, value is its index
  unordered_map<char, int> map

  // Point to the left index of substring
  int j = 0;

  // Record the the max_length of substring
  int max_length = 0;
  
  // Traverse whole string, O(N)
  for(int i=0;i<InputString.size();i++)
  {
    // Not in the map yet, directly insert
    if(!map.count(InputString[0]))
      map[InputString[0]] = i;
    else
    {
      int duplicate_index = map[InputString[0]];
      
      // Remove the value from index until next index of duplicate and update the j
      while(j<=duplicate_index)
      {
        map.erase(InputString[j])
        j++;
      }
      // Insert the current into map
      map[InputString[i]] = i;
    }
    max_length = max(max_length, i-j+1);
  }
}
````
### Palindromic 
[5_Longest_Palindromic_Substring](5_Longest_Palindromic_Substring.cpp)  
````c++
int ExpandFromCenter(InputString, int start, int end)
{
  while(start>=0 && end<InputString.size() && InputString[start] == InputString[end])
  {
    start--;
    end++;
  }
  return (end-start-1);
}
Longest_Palindromic(InputString)
{
  // Record the longest substirng left index and right index
  int left = 0;
  int right = 0;

  for(int i=0; i<InputStirng.size(); i++)
  {
    // Palindromic is odd
    int len1 = ExpandFromCenter(InputStirng, i, i);
    // Palindromic is even 
    int len2 = ExpandFromCenter(InputString, i, i+1);

    int len = max(len1, len2);

    // if current len longer than longest substirng, update left index and right index
    if(len > right-left+1)
    {
      // Represent if this substring is even
      if(len % 2 == 0)
        left = i - len/2 + 1;
      else
        left = i - len/2;
      right = i + len/2
    }
  }
  return InputString.substr(left, right-left+1);  
}
````

# Tree
## DFS
### In-Order
Traverse the value from small to big  
[94_Binary_Tree_Inorder_Traversal](94_Binary_Tree_Inorder_Traversal.cpp)  
``Recursive version``
````c++
InOrder(node)
{
  if(!node)
    return 
  
  InOrder(node->left)
  cout<<node->val<<endl;
  InOrder(node->right)
}
int main(node)
{
  InOrder(node)
}
````
``Iterative version``
````c++
int main(Node* root)
{
  stack<Node* > sta;
  Node* node = root
  while(node || !sta.empty())
  {
    if(node)
    {
      sta.push(node);
      
      // Move to next node
      node = node->left;
    }
    else
    {
      Node* temp = sta.pop();
      sta.pop();
      
      // Print the valuef
      cout << temp->val << endl;

      node = temp->right;  
    }
  }
}
````
### Pre-Order
[144_Binary_Tree_Preorder_Traversal](144_Binary_Tree_Preorder_Traversal.cpp)  
``Recursive version``
````c++
PreOrder(node)
{
  if(!node)
    return 
  
  cout<<node->val<<endl;
  PreOrder(node->left)
  PreOrder(node->right)
}
int main(node)
{
  PreOrder(node)
}
````
``Iterative version``
````c++
int main(Node* root)
{
  Node* node = root;
  stack<Node*> sta;
  
  while(node || !sta.empty())
  {
    if(node)
    {
      sta.push(node);

      // Print the value
      cout << node->val << endl;
      
      // Move to next node
      node = node->left;
    }
    else
    {
      Node* temp = sta.top();
      sta.pop();
      node = temp->right;
    }
    
  }
}
````
### Post-Order
[145_Binary_Tree_Postorder_Traversal](145_Binary_Tree_Postorder_Traversal.cpp)  
``Recursive version``
````c++
PostOrder(node)
{
  if(!node)
    return;

  PostOrder(node->left);
  PostOrder(node->right);
  cout << node->val << endl;

}
int main(node)
{
  PostOrder(node);
}
````
``Iterative version``
````c++
int main(Node* root)
{
  Node* node = root;
  stack<Node*> sta;
  vector<int> output;
  
  while(node || !sta.empty())
  {
    if(node)
    {
      sta.push(node);
      output.insert(output.begin(), node->val);
      // 先走右邊
      node = node->right;
    }
    else
    {
      Node* temp = sta.top();
      sta.pop();
      node = temp->left;
    }
  }
}
````
## BFS
````c++
void BFS(TreeNode* node)
{
  // Use queue to do BFS
  queue<TreeNode* >que;

  // Push the first node into queue
  que.push(node);
  while(!que.empty())
  {
    TreeNode* current = que.front();
    que.pop();
    cout << current->val <<endl;

    if(current->left)
      que.push(current->left);
    if(current->right)
      que.push(current->right);
  }
}
````


# Sorting
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
# Graph
可參考這系列Graph文章
[Graph intro](http://alrightchiu.github.io/SecondRound/graph-introjian-jie.html)  

### BFS
[207.course-schedule](207.course-schedule.cpp)  
[133_Clone_Graph](133_Clone_Graph.cpp)  
[310.minimum-height-trees](310.minimum-height-trees.cpp)  

1. 做完一次BFS可產生start_node到任何一個node ``shortest path``
並利用Predecessor可以back tracking回去找出這條路徑確切的軌跡
2. 可利用visit判斷是否有環
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
[207.course-schedule](207.course-schedule.cpp)  
[133_Clone_Graph](133_Clone_Graph.cpp)  
[399.evaluate-division](399.evaluate-division.cpp)  
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
### Topological Sort 
[210.course-schedule-ii](210.course-schedule-ii.cpp)  
In directed graph中, node之間是有先後順序, 要找出一條從頭到尾的順序
ex: 修課從basic -> advance的這條路線
````c++
Topological_Sort
{
  DFS(Graph) ->找出個別node的finish time

  // pair -> (node, finish_time)
  vector<pair<int, int>> LargeToSmall
  LargeToSmall.resize(V)
  for(int i=0;i<finish_time.size();i++)
  {
    // First 紀錄node_index, second紀錄所對應的finish_time
    LargeToSmall[i].first = i;
    LargeToSmall[i].second = finish_time[i];
  }

  // 根據finish time做sorting, 從大到小
  sort(LargeToSamll.begin(), LargeToSmall.end(), [](auto a, auto b){a.second>b.second;});

  // 最後這個順序就是出來的結果
  for(auto v:LargetToSmall)
    cout << v.first << " ";
}
````
# Trie
將搜尋string的time complexity降成``O(M)``
(M is the max size of string in trie)  
[208.implement-trie-prefix-tree](208.implement-trie-prefix-tree.cpp)
````c++
class TrieNode
{
  // Constructor
  TrieNode()
  {
    isEnd = false;

    for(int i=0; i<26; i++)
      child[i] = nullptr;
  }

  TrieNode* child[26];
  bool isEnd;
}
class Trie
{
  // Constructor
  Trie()
  {
    root = new TrieNode();
  }

  // Insert the string into trie
  Insert(str)
  {
    TrieNode* node = root;
    for(auto& v: str)
    {
      // 將char轉成0~25之間的index
      int index = v-'a';
      
      // 此char沒有在trie裡面, insert it
      if(!node->child[index])
        node->child[index] = new TrieNode;
      
      // Move to next level
      node = node->child[index]
    }
    // 將最後一個node標記為此string的end
    node->isEnd = true;
  }

  // Search the string into trie
  Search(str)
  {
    TrieNode* node = root;
    for(auto& v: str)
    {
      int index = v-'a';

      // 如果此char不在trie裡面, 那就一定代表此string不在裡面
      if(!node->child[index])
        return false;
      
      node = nodex->child[index];
    }
    // 要確認是否此為結尾, 如果為結尾代表此input string有在trie裡面, 反之則代表只是其他string的prefix
    return node->isEnd;
  }

private:
  TrieNode* root;
}
````
