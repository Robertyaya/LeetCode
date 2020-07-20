#include <bits/stdc++.h>
using namespace std;
/**
 * Time: O(N), Space: O(H)
 * 解題流程: Recursive下去, 先從小問題解起, 分別解left subtree's height and right subtre''s height
 * 之後再和root merge起來, return 回此subtree的height
 * isbal是用來判斷過程中是否有發生unbalance的情況, 如果有的話直接設為false
 * 並且有一個地方可以optimize的就是在recursive function一開始加上那個判斷式, return回多少的數字不重要
 * 利用這樣如果在recursive過程發現此時subtree is unbalance那這樣可以直接return
 */

int CalculateHeight(TreeNode *node, bool &isbal)
{
    if (!isbal)
        return 0;

    // Base case
    if (node == nullptr)
        return 0;

    int leftheight = CalculateHeight(node->left, isbal);
    int rightheight = CalculateHeight(node->right, isbal);
    if (abs(leftheight - rightheight) > 1)
        isbal = false;
    return max(leftheight, rightheight) + 1;
}

bool isBalanced(TreeNode *root)
{
    bool isbal = true;
    CalculateHeight(root, isbal);
    return isbal;
}
