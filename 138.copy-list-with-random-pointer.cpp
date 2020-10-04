/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
/**
 * Time: O(N), Space: O(1) (因為沒有使用hash map)
 * 解題流程: 這題關鍵是在original linkedlist中insert進去相同的node之後再各別斷開成兩個linkedlist
 * 因此沒有使用到hash map
 * ex: ()代表random pointer
 * 1(2)->2(3)->3(4)->null
 * 
 * 1. Insert node (the first while loop)
 * 1(2) -> 1(null) -> 2(3) -> 2(null) -> 3(4) -> 3(null) -> null
 * 
 * 2. 放入random pointer
 * runner->next->random 代表的就是copy的那個的random pointer
 * runner->random->next (其中runner->random代表的就是current node的random pointer, 但此random pointer是指向original linkedlist 並不是copy的那個, 因此要->next才是指向copy的那個node)
 * 
 * 3. 最後則是要斷開original linkedlist and copy linkedlist
 * 1(2) = copy's 1(2)->next
 * 連好original node後再連copy node
 * copy's 1(2)->next = 1(2)->next->next (代表的就是1(2)->next這個node的copy)
 * 最後在尾巴的部分要注意會有null的出現
 * 
 */
class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return nullptr;

        Node *runner = head;
        // Insert node
        while (runner)
        {
            Node *insert = new Node(runner->val);
            insert->next = runner->next;
            runner->next = insert;
            runner = insert->next;
        }

        // Connect the random pointer
        runner = head;
        while (runner)
        {
            if (runner->random == nullptr)
                runner->next->random = nullptr;
            else
                runner->next->random = runner->random->next;
            runner = runner->next->next;
        }

        // 斷開linkedlist
        runner = head;
        Node *output = runner->next;
        Node *output_runner = output;
        while (runner)
        {
            // 接回原本的node
            runner->next = output_runner->next;
            runner = runner->next;

            if (runner == nullptr)
                output_runner->next = nullptr;
            else
                output_runner->next = runner->next;
            output_runner = output_runner->next;
        }
        return output;
    }
    /**
 * Time: O(N), Space: O(N)
 */
    Node *copyRandomList(Node *head)
    {
        Node *head_runner = head;
        Node *answer = new Node(-1);
        Node *answer_runner = answer;

        // key為original node, value為copy node
        unordered_map<Node *, Node *> map;
        while (head_runner)
        {
            // 將original node和copy node之間利用map對起來
            answer_runner->next = new Node(head_runner->val);
            answer_runner = answer_runner->next;
            map[head_runner] = answer_runner;
            head_runner = head_runner->next;
        }

        answer_runner = answer->next;
        while (head)
        {
            // 根據map可以快速找到random pointer指向的那個copy node
            if (!head->random)
                answer_runner->random = nullptr;
            else
                answer_runner->random = map[head->random];
            answer_runner = answer_runner->next;
            head = head->next;
        }
        return answer->next;
    }
};
// @lc code=end
