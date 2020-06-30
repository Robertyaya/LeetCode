#include <bits/stdc++.h>
using namespace std;
/**
 * Time: O(N), Space: O(N+H)
 * 解題流程: 
 * 和problem105相同, 利用postorder找出rootvalue, 有了root value後再從inorder找出root_index
 * 有了inorder的root_index就可以知道preorder and inrder的left subtree and right subtree分別從index多少到多少
 * 差別只在於postorder的root會在最後面, 而preorder的root會在最前面
 */
TreeNode *buildTreeRecursive(vector<int> &inorder, int i_start, int i_end, vector<int> &postorder, int p_start, int p_end, unordered_map<int, int> &map)
{
  if (i_start == i_end)
  {
    TreeNode *node = new TreeNode(inorder[i_start]);
    return node;
  }

  if (i_start > i_end)
    return NULL;

  int tree_root_value = postorder[p_end];
  int inorder_root_index = map[tree_root_value];
  int left_num = inorder_root_index - i_start;

  TreeNode *node = new TreeNode(tree_root_value);

  node->left = buildTreeRecursive(inorder, i_start, inorder_root_index - 1, postorder, p_start, p_start + left_num - 1, map);

  node->right = buildTreeRecursive(inorder, inorder_root_index + 1, i_end, postorder, p_start + left_num, p_end - 1, map);

  return node;
}
TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
  unordered_map<int, int> map;
  for (int i = 0; i < inorder.size(); i++)
  {
    map[inorder[i]] = i;
  }
  return buildTreeRecursive(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, map);
}
