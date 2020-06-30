#include <bits/stdc++.h>
using namespace std;
/**
 * DP version
 * 解題流程: 和Recursive method概念相同, 但dp version是直接從小問題解到大問題
 * dp[0]代表的是[]所有可能BST
 * dp[1]代表的是[1]所有可能BST
 * dp[2]代表的是[1,2]所有可能BST
 * 因此題目要求dp[1,2,...n]所有可能即為計算dp[n]
 * 總共4層for迴圈
 * 第一層:
 * Traverse dp的size, 因此從1填到n size
 * 
 * 第二層:
 * 根據當下的dp size去取各別數值當root
 * ex: if i=3, [1,2,3] 此層就是從1~3輪流當root
 * 當選1為root, 左子樹數量為0, 右子樹數量為2
 * 關鍵為offset, 此代表的意義是dp儲存的都是從1開始valid BST, ex: [1,2,3] 和 [2,3,4]
 * 這兩個valid BST樣式完全相同, 差別只在於裡面的數值會有一個offset
 * 而此處的offset用意就是從dp取出[1,2,3]所有的valid BST後把所有數值都加上offset, 即為[2,3,4]所代表的valid BST
 * 而這件事就是TreeClone這個function在做的事
 * 
 * 第三層 and 第四層
 * Traverse左子樹和右子樹的所有可能
 * ex: [1,2]共兩種可能 [1,NULL, NULL, 2] amd [2,1 NULL, NULL]
 * 這兩層就是去travese這幾種可能左右配對並和root merge在一起之後塞到ans裡面
 * 當所有都配對完之後再將ans塞到dp裡面, 此時就是代表求得dp[i]的數值
 */
TreeNode *TreeClone(TreeNode *base, int offset)
{
  // Base case
  if (base == nullptr)
    return nullptr;

  // Deep copy, 不能直接相等, 這樣會指向同一個TreeNode, 而是要new出來後將數值填進去
  TreeNode *newTree = new TreeNode(base->val + offset);
  newTree->left = TreeClone(base->left, offset);
  newTree->right = TreeClone(base->right, offset);

  return newTree;
}
vector<TreeNode *> generateTrees(int n)
{
  if (n == 0)
    return {};

  vector<vector<TreeNode *>> dp;
  dp.resize(n + 1);

  // Initialize dp[0]
  dp[0] = {NULL};

  // Fill the DP
  for (int i = 1; i <= n; i++)
  {
    vector<TreeNode *> ans;
    // Traverse all root
    for (int root = 1; root <= i; root++)
    {
      int left = root - 1;  // 左子樹的長度
      int right = i - root; // 右子樹的長度
      int offset = root;

      // Traverse 左子樹所有可能
      for (int j = 0; j < dp[left].size(); j++)
      {
        // Traverse 右子樹所有可能
        for (int k = 0; k < dp[right].size(); k++)
        {
          // 只有右子樹需要加上offset, 因為左子樹都是從1開始, 和dp裡面save的數值相同
          TreeNode *LeftSubTree = dp[left][j];
          TreeNode *RightSubTree = TreeClone(dp[right][k], offset);

          // Merge the current root with LeftSubTree and RightSubTree
          TreeNode *temp_tree = new TreeNode(root, LeftSubTree, RightSubTree);
          ans.push_back(temp_tree);
        }
      }
    }
    dp[i] = ans;
  }

  return dp[n];
}
/**
 * Recursive 
 * 解題流程: 要找出所有valid BST的可能並且存到vector中. 在vector中每一個TreeNode* 代表的就是一種valid BST
 * 觀念相同一樣是輪流當root, 選定一個當root後, return 回left sub tree and right sub tree的所有種可能
 * 之後Merge起來
 * ex: 
 * 第一層: 
 * [1,2,3,4,5] 選定3為root時此時left為[1,2], right為[4,5]
 * 第二層: 
 * 1. 先處理[1,2]->輪流當root
 * 
 * If 1 is root
 * leftSubTree = NULL
 * rightSubTree = [ [2] ]
 * Merge: [ [NULL, 1, 2] ]
 * push_back into vector: [ [NULL, 1, 2] ]
 * 
 * 到下一個 
 * If 2 is root
 * leftSubTree = [ [1] ]
 * rightSubTree = [ [NULL] ]
 * Merge: [ [1, 2, NULL] ]
 * push_back into vector: [ [NULL, 1, 2], [1, 2, NULL]]
 * 
 * 接著再return回第一層的"LeftsubTree=" [ [NULL, 1, 2], [1, 2, NULL]]
 * 共有兩種可能
 * rightsubTree也是相同做法
 * 因此在第一層我們在以root=3的情況下做merge就會從left sub tree and right sub tree各選一個可能做merge
 * leftSubTree[j], rightSubTree[k] 就是各選一種可能的概念
 * 選[NULL, 1, 2] or [1, 2, NULL]的意思
 * 
 */
vector<TreeNode *> FindBST(int start, int end)
{
  vector<TreeNode *> ans;
  if (start > end)
    ans.push_back(NULL);
  else if (start == end)
  {
    TreeNode *node = new TreeNode(start);
    ans.push_back(node);
  }
  else
  {
    for (int i = start; i <= end; i++)
    {
      vector<TreeNode *> leftSubTree = FindBST(start, i - 1);
      vector<TreeNode *> rightSubTree = FindBST(i + 1, end);
      for (int j = 0; j < leftSubTree.size(); j++)
      {
        for (int k = 0; k < rightSubTree.size(); k++)
        {
          // Merge root and leftSubTree and rightSubTree
          TreeNode *root = new TreeNode(i, leftSubTree[j], rightSubTree[k]);
          ans.push_back(root);
        }
      }
    }
  }
  return ans;
}
vector<TreeNode *> generateTrees(int n)
{
  if (n == 0)
    return {};

  return FindBST(1, n);
}
