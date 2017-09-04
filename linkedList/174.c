/*
 * title：容易-174.删除链表中倒数第n个节点 
 * desc:给定一个链表，删除链表中倒数第n个节点，返回链表的头节点。
 * e.g.:给出链表1->2->3->4->5->null和 n = 2.
 *      删除倒数第二个节点之后，这个链表将变成1->2->3->5->null.
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
     * @return: The head of linked list.
     */
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // write your code here
        ListNode *p;
        int cnt = 0;
        p = head;
        while(p!=NULL)
        {
            cnt++;
            p = p->next;
        }
        ListNode *q;
        p = head;
        q = head;
        
        int i = 1;
        while(p!=NULL)
        {
            if((i == 1) && (i == (cnt+1-n)))
            {
                head = p->next;
                delete p;
                break;
            }
            if(i == (cnt + 1 -n))
            {
                q->next = p->next;
                delete p;
                break;
            }
            q = p;
            p = p->next;
            i++;
        }
        
        return head;
    }
};


