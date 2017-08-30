/*
 * title：容易-165.合并两个排序链表
 * desc:将两个排序链表合并为一个新的排序链表
 * e.g.:给出 1->3->8->11->15->null，2->null， 返回 1->2->3->8->11->15->null。
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
     * @param ListNode l1 is the head of the linked list
     * @param ListNode l2 is the head of the linked list
     * @return: ListNode head of linked list
     */
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // write your code here
        ListNode *newHead, *s, *p, *q, *temp;
        newHead = new ListNode(0);
        newHead->next = l1;
        p = l2;
        while(p != NULL)
        {
            s = newHead;
            q = newHead->next;
            while((q != NULL) && (p->val>q->val))
            {
                s = q;
                q = q->next;
            }
            s->next = p;
            temp = p->next;
            p->next = q;
            p = temp;
        }
        temp = newHead->next;
        delete newHead;
        newHead = NULL;
        return temp;
    }
};