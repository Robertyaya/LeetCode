#include <bits/stdc++.h>
using namespace std;

/**
 * Recursive version (較快)
 * Time: O(N), Space: O(H)
 */
bool DFS(TreeNode *p, TreeNode *q)
{
    if ((p == nullptr && q != nullptr) || (p != nullptr && q == nullptr))
        return false;
    if (p == nullptr && q == nullptr)
        return true;

    if (p->val != q->val)
        return false;
    if (!DFS(p->left, q->left))
        return false;
    if (!DFS(p->right, q->right))
        return false;
    return true;
}
bool isSameTree(TreeNode *p, TreeNode *q)
{
    return DFS(p, q);
}

/** 
 * Iterative version
 */
bool isSameTree(TreeNode *p, TreeNode *q)
{
    if ((p == nullptr && q != nullptr) || (p != nullptr && q == nullptr))
        return false;

    stack<TreeNode *> stack_p;
    stack<TreeNode *> stack_q;
    while (p || !stack_p.empty())
    {
        if ((p == nullptr && q != nullptr) || (p != nullptr && q == nullptr))
            return false;

        if (p)
        {
            if (p->val != q->val)
                return false;

            stack_p.push(p);
            stack_q.push(q);
            p = p->left;
            q = q->left;
        }
        else
        {
            TreeNode *nodeq = stack_q.top();
            TreeNode *nodep = stack_p.top();
            stack_q.pop();
            stack_p.pop();
            p = nodep->right;
            q = nodeq->right;
        }
    }
    return true;
}