/*
 * title：容易-96.链表划分
 * desc:你有两个用链表代表的整数，其中每个节点包含一个数字。
 *      数字存储按照在原来整数中相反的顺序，使得第一个数字位于链表的开头。
 *      写出一个函数将两个整数相加，用链表形式返回和。
 * e.g.:给定链表 1->4->3->2->5->2->null，并且 x=3，返回 1->2->2->4->3->5->null
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
    /*
     * @param head: The first node of linked list
     * @param x: An integer
     * @return: A ListNode
     */
    ListNode * partition(ListNode * head, int x) {
        // write your code here
        ListNode *one = new ListNode(0);
        ListNode *two = new ListNode(0);
        one->next = NULL;
        two->next = NULL;
        ListNode *ptOne = one;
        ListNode *ptTwo = two;
        ListNode *original = head;
        ListNode *temp;
        while(original != NULL)
        {
            if(original->val < x)
            {
                ptOne->next = original;
                ptOne = original;
            }
            else
            {
                ptTwo->next = original;
                ptTwo = original;
            }
            original = original->next;
        }
        ptOne->next = two->next;
        ptTwo->next = NULL;
        temp = one->next;
        delete one;
        delete two;
        return temp;
        
        
    }
};