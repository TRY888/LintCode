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
    bool hasCycle(ListNode *head) {
        // write your code here
        ListNode *p, *q;
        if(head == NULL)
            return false;
        p = head;
        q = head->next;
        while(p!=NULL && q !=NULL)
        {
            if(p == q)
                return true;
            p = p->next;
            if(q->next != NULL)
                q = q->next->next;
            else
                return false;
        }
        return false;
    }
};

