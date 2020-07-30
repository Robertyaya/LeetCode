/*
 * @lc app=leetcode id=117 lang=cpp
 *
 * [117] Populating Next Right Pointers in Each Node II
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution
{
    /**
     * Time: O(N), Space: O(1) (Only use the queue size)
     * Level-order traverse
     */
public:
    Node *connect(Node *root)
    {
        if (!root)
            return root;
        Node *node = root;
        queue<Node *> que;
        que.push(root);
        while (!que.empty())
        {
            for (int i = que.size(); i >= 1; i--)
            {
                Node *temp = que.front();
                que.pop();
                if (i == 1) // 當為那一層的最後一個node時, 則指向NULL
                    temp->next = NULL;
                else
                    temp->next = que.front(); // 指向下一個node

                if (temp->left)
                    que.push(temp->left);
                if (temp->right)
                    que.push(temp->right);
            }
        }
        return root;
    }
};
// @lc code=end
