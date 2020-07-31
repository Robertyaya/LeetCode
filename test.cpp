#include <bits/stdc++.h>
using namespace std;

int main()
{
  char str = 'A';
  char a = 'B';
  if (a > str)
    cout << "FUCK" << endl;

  cout << char(str + 32) << endl;
}

void DFS(TreeNode *node, int current_sum, int &sum)
{
  current_sum = current_sum * 10 + node->val;

  // Arrive the leaf
  if (!node->left && !node->right)
  {
    sum += current_sum;
  }
  if (node->left)
    DFS(node->left, current_sum, sum);
  if (node->right)
    DFS(node->right, current_sum, sum);
}
int sumNumbers(TreeNode *root)
{
  if (!root)
    return 0;
  int sum = 0;
  DFS(root, 0, sum);
  return sum;
}
