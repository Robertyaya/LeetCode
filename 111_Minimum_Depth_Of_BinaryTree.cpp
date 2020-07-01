#include <bits/stdc++.h>
using namespace std;
/**
 * 
 * Time: O(N), Space: O(H)
 * 解題流程: 此題要求root到leaf的最短距離, Recursive下去每次return min(左子樹和右子樹的高度)
 * 這邊有一細節是如果左子樹或右子樹height為0, 代表沒有leaf
 * 因此不能直接取ㄓ0 return, 而是要回傳max的那個height, 因為那才是leaf
 * 
 */
int minDepthRecursive(TreeNode *node)
{
    if (node == nullptr)
        return 0;

    int left_height = minDepthRecursive(node->left);
    int right_height = minDepthRecursive(node->right);

    // Calculate the height of subtree
    // 左子樹或右子樹沒有node, 因此此時要回傳有node的距離, 因為題目要求root to "leaf"
    if (left_height == 0 || right_height == 0)
        return max(left_height, right_height) + 1;
    else
        return min(left_height, right_height) + 1;
}
int minDepth(TreeNode *root)
{
    return minDepthRecursive(root);
}