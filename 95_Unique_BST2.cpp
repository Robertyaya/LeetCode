#include <bits/stdc++.h>
using namespace std;
/**
 * Recursive version
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
          // Merge and push back into vector
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
