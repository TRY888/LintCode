/*
 * title：容易-166.链表倒数第n个节点
 * desc:找到单链表倒数第n个节点，保证链表中节点的最少数量为n。
 * e.g.:给出链表 3->2->1->5->null和n = 2，返回倒数第二个节点的值1.
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
     * @param n: An integer.
     * @return: Nth to last node of a singly linked list. 
     */
    ListNode *nthToLast(ListNode *head, int n) {
        // write your code here
        ListNode *p;
        int cnt = 0;
        int i = 1;
        p = head;

        while(p!=NULL)
        {
            cnt++;
            p = p->next;
        }
        p = head;
        while(p!=NULL)
        {
            if(i == (cnt + 1 -n))
            {
                break;
            }
            p = p->next;
            i++;
        }
        return p;
        
    }
};


