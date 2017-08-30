/*
 * title：入门-452.删除链表中的元素
 * desc:删除链表中等于给定值val的所有节点。
 * e.g.:给出链表 1->2->3->3->4->5->3, 和 val = 3, 你需要返回删除3之后的链表：1->2->4->5。
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


class Solution {
public:
    /*
     * @param head: a ListNode
     * @param val: An integer
     * @return: a ListNode
     */
    ListNode * removeElements(ListNode * head, int val) {
        // write your code here
        ListNode *p,*s,*temp;
        p = s = head;
        while(p != NULL)
        {
            if(p->val == val)
            {
                if(p == head)
                {
                    temp = p;
                    p = p->next;
                    head = p;
                    free(temp);
                }
                else
                {
                    temp = p;
                    p = p->next;
                    s->next = p;
                    free(temp);
                }
                continue;
            }
            s = p;
            p = p->next;
        }
        return head;
    }
};