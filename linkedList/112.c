/*
 * title：容易-112.删除排序链表中的重复元素
 * desc:给定一个排序链表，删除所有重复的元素每个元素只留下一个。
 * e.g.:给出 1->1->2->null，返回 1->2->null
 *      给出 1->1->2->3->3->null，返回 1->2->3->null
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
     * @return: head node
     */
    ListNode *deleteDuplicates(ListNode *head) {
        // write your code here
        if(head == NULL)
            return NULL;
        ListNode *p = head;
        ListNode *q = head;
        int x = p->val;
        ListNode *temp;
        p = p->next;
        while(p != NULL)
        {
            if(p->val == x)
            {
                temp = p;
                q->next = p->next;
                p = p->next;
                delete temp;
            }
            else
            {
                x = p->val;
                q = p;
                p = p->next;
            }
        }
        return head;
    }
};