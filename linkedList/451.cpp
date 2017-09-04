/*
 * title：容易-451.两两交换链表中的节点
 * desc:给一个链表，两两交换其中的节点，然后返回交换后的链表。
 * e.g.:给出 1->2->3->4, 你应该返回的链表是 2->1->4->3。
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