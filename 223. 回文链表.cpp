/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


// class Solution {
// public:
//     /*
//      * @param head: A ListNode.
//      * @return: A boolean.
//      */
//     bool isPalindrome(ListNode * head) {
//         // write your code here
//         int len = 0;
//         ListNode *p = head;
//         while(p!=NULL)
//         {
//             p = p->next;
//             len++;
//         }
//         p = head;
//         ListNode *newHead, *temp;
//         newHead = temp = NULL;
//         for(int i=0; i<(len/2); ++i)
//         {
//             temp = p->next;
//             p->next = newHead;
//             newHead = p;
//             p = temp;
//         }
//         if(len%2 != 0)
//             p = p->next;
//         while(newHead!=NULL && p!=NULL)
//         {
//             if(newHead->val != p->val)
//                 return false;
//             newHead = newHead->next;
//             p = p->next;
//         }
//         return true;
//     }
// };

class Solution {
public:
    /*
     * @param head: A ListNode.
     * @return: A boolean.
     */
    bool isPalindrome(ListNode * head) {
        // write your code here
        ListNode *p = head;
        int len = 0;
        while(p!=NULL)
        {
            len++;
            p = p->next;
        }
        ListNode *s, *temp;
        s = NULL;
        p = head;
        for(int i=1; i<=len/2; i++)
        {
            temp = p->next;
            p->next = s;
            s = p;
            p = temp;
        }
        if(len%2 != 0)
            p = p->next;
        while(s!=NULL && p!=NULL)
        {
            if(s->val != p->val)
                return false;
            s = s->next;
            p = p->next;
        }
        return true;


    }
};
