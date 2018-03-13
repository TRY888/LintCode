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
// class Solution {
// public:
//     /**
//      * @param head: The first node of linked list.
//      * @param n: An integer.
//      * @return: Nth to last node of a singly linked list.
//      */
//     ListNode *nthToLast(ListNode *head, int n) {
//         // write your code here
//         ListNode *p;
//         int cnt = 0;
//         int i = 1;
//         p = head;

//         while(p!=NULL)
//         {
//             cnt++;
//             p = p->next;
//         }
//         p = head;
//         while(p!=NULL)
//         {
//             if(i == (cnt + 1 -n))
//             {
//                 break;
//             }
//             p = p->next;
//             i++;
//         }
//         return p;

//     }
// };

class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @param n: An integer.
     * @return: Nth to last node of a singly linked list.
     */
    ListNode *nthToLast(ListNode *head, int n) {
        // write your code here
        int cnt = 0;
        ListNode *p = head;
        while(p!=NULL)
        {
            cnt++;
            p = p->next;
        }
        p = head;
        int i=1;
        while(p!=NULL && i<cnt-n+1)
        {
            p = p->next;
            i++;
        }
        return p;
    }
};
