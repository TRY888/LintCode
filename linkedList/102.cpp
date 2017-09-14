/*
 * title：中等-102.带环链表
 * desc:给定一个链表，判断它是否有环。
 * e.g.:给出 -21->10->4->5, tail connects to node index 1，返回 true
 *      不要使用额外的空间
 */

/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: True if it has a cycle, or false
     */
/*
    void insert(ListNode **tail, int addr)
    {
        ListNode *newNode = new ListNode(addr);
        newNode->next = NULL;
        (*tail)->next = newNode;
        *tail = newNode;
    }
    
    bool isAddrExistInList(ListNode *head, int addr)
    {
        ListNode *p = head;
        while(p != NULL)
        {
            if(p->val == addr)
                return true;
            p = p->next;
        }
        return false;
    }
    
    bool hasCycle(ListNode *head) {
        // write your code here
        ListNode *newHead = new ListNode(0);
        newHead->next = NULL;
        ListNode *tail, *p;
        tail = newHead;
        p = head;
        while(p!=NULL)
        {
            if(isAddrExistInList(newHead, reinterpret_cast<long>(p)))
                return true;
            else
                insert(&tail, reinterpret_cast<long>(p));
            p = p->next;
        }
        return false;
    }
*/

    bool hasCycle(ListNode *head) {
        // write your code here
        ListNode *fast = head, *slow = head;
        while(fast!=NULL && fast->next!=NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow)
                return true;
        }
        return false;
    }
};


