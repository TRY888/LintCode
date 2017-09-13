/*
 * title：中等-223.回文链表
 * desc:设计一种方式检查一个链表是否为回文链表。
 * e.g.:1->2->1 就是一个回文链表。
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
     * @param head: A ListNode.
     * @return: A boolean.
     */
    bool isPalindrome(ListNode * head) {
        // write your code here
        int len = 0;
        ListNode *p = head;
        while(p!=NULL)
        {
            p = p->next;
            len++;
        }
        p = head;
        ListNode *newHead, *temp;
        newHead = temp = NULL;
        for(int i=0; i<(len/2); ++i)
        {
            temp = p->next;
            p->next = newHead;
            newHead = p;
            p = temp;
        }
        if(len%2 != 0)
            p = p->next;
        while(newHead!=NULL && p!=NULL)
        {
            if(newHead->val != p->val)
                return false;
            newHead = newHead->next;
            p = p->next;
        }
        return true;
    }
};