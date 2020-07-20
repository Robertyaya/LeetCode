#include <bits/stdc++.h>
using namespace std;
/**
 * Time: O(N), Sapce: O(N+H) (N is the size of map, H is the height of tree)
 * 解題流程: 要從preorder and inorder回復成Binary tree
 * Preorder: [ root [left subtree] [right subtree] ]
 * Inorder: [ [left subtree] root [right subtree] ]
 * Preorder和inorder都會滿足此結構
 * 整個邏輯就是
 * 1. 先從Preorder取得root, 因為就是第一個
 * 2. 從Inorder取得root index (此處利用unordermap來快速找到此index)
 * 3. 從Inorder取得root index之後, 我們就可知道left subtree和 right subtree"個數". 因為在inorder中left subtree就是root左邊全部的數字, right subtree就是root右邊全部的數字
 * 4. 有了個數之後, 我們就也可以知道再preorder中left subtree的index是從多少到多少, right subtree的index是從多少到多少
 * 5. 有了各別sub tree之後我們可以recursive下去把它當成一個新的preorder vector and inorder vector持續分解問題
 * ex: 
 * preorder: [3,9,20,15,7]
 * inorder: [9,3,15,20,7]
 * 1. 先從preorder取得3為root
 * 2. 找出3的index後, 知道[9]為left subtree, [15,20,7]為right subtree
 * 3. 我們有了個數可以推得在preorder index幾到幾為left subtree 幾到幾為right subtree
 * 4. 有了preorder and inorder的start index and end index 繼續recursive下去
 * 3. 因此我們將preorder中[9] and [20,15,7] 和inorder中[9] and [15,20,7]分別作為left and right繼續recursive下去直到到達base condition
 */
TreeNode *buildTreeRecursive(vector<int> &preorder, int p_start, int p_end, vector<int> &inorder,
                             int i_start, int i_end, unordered_map<int, int> &map)
{
  // 代表此時preorder and inorder都只有一個數字, 因為index指到同一個, 因此直接return此時的treenode
  if (p_start == p_end)
  {
    TreeNode *node = new TreeNode(preorder[p_start]);
    return node;
  }

  // 代表此時preorder and inorder為[]空的, 因此代表為null
  if (p_start > p_end)
    return NULL;

  int tree_root_value = preorder[p_start];
  // Find tree root in inorder vector
  int inorder_root_index = map[tree_root_value];

  // Record the left sub tree number
  int leftNum = inorder_root_index - i_start;

  TreeNode *ans = new TreeNode(tree_root_value);

  // Recursive計算left subtree
  ans->left = buildTreeRecursive(preorder, p_start + 1, p_start + leftNum, inorder, i_start, inorder_root_index - 1);

  // Recursive計算right subtree
  ans->right = buildTreeRecursive(preorder, p_start + leftNum + 1, p_end, inorder, inorder_root_index + 1, i_end);

  return ans;
}
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
  // Key: tree node value, value: index in inorder vector
  unordered_map<int, int> map;
  for (int i = 0; i < inorder.size(); i++)
  {
    map[inorder[i]] = i;
  }
  return buildTreeRecursive(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, map);
}

preorder = [ root, left_subtree, right_sub_tree ] root_index = preorder(p_start);
