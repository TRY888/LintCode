/*
 * title：中等-380.两个链表的交叉
 * desc:请写一个程序，找到两个单链表最开始的交叉节点。
 * e.g.:给出 1->2->3->4, 你应该返回的链表是 2->1->4->3。
 *      注意事项
 *      如果两个链表没有交叉，返回null。
 *      在返回结果后，两个链表仍须保持原有的结构。
 *      可假定整个链表结构中没有循环。
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
    /**
     * @param headA: the first list
     * @param headB: the second list
     * @return: a ListNode
     */
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // write your code here
        ListNode *A,*B;
        A = headA;
        B = headB;
        while(A!=NULL)
        {
            B = headB;
            while(B!=NULL)
            {
                if(A == B)
                    return A;
                B = B->next;
            }
            A = A->next;
        }
        if(A == NULL)
            return NULL;
        return A;
    }
};