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
     * @return: The head of linked list.
     */
    ListNode *insertionSortList(ListNode *head) {
        // write your code here
        ListNode *list_head = new ListNode(INT_MIN);
        ListNode *prior, *temp, *p, *q;
        p = head;
        while(p!=NULL)
        {
            prior = list_head;
            q = list_head;
            while(q!=NULL && p->val>=q->val)
            {
                prior = q;
                q = q->next;
            }
            temp = p->next;
            prior->next = p;
            p->next = q;
            p = temp;
        }
        temp = list_head->next;
        delete list_head;
        return temp;
    }
};
