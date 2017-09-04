/*
 * title：容易-35.翻转链表
 * desc:翻转一个链表
 * e.g.:给出一个链表1->2->3->null，这个翻转后的链表为3->2->1->null
 */

/**
 * Definition of ListNode
 * 
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 * 
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */


class Solution {
public:
    /*
     * @param head: n
     * @return: The new head of reversed linked list.
     */
    ListNode * reverse(ListNode * head) {
        // write your code here
        ListNode *newHead = new ListNode(0);
        newHead->next = NULL;
        ListNode *p,*temp,*s;
        p = head;
        s = newHead->next;
        while(p!=NULL)
        {
            newHead->next = p;
            temp = p->next;
            p->next = s;
            s = p;
            p = temp;
        }
        temp = newHead->next;
        delete newHead;
        return temp;
    }
};