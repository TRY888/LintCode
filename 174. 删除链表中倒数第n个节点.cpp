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
//      * @return: The head of linked list.
//      */
//     ListNode *removeNthFromEnd(ListNode *head, int n) {
//         // write your code here
//         ListNode *p;
//         int cnt = 0;
//         p = head;
//         while(p!=NULL)
//         {
//             cnt++;
//             p = p->next;
//         }
//         ListNode *q;
//         p = head;
//         q = head;

//         int i = 1;
//         while(p!=NULL)
//         {
//             if((i == 1) && (i == (cnt+1-n)))
//             {
//                 head = p->next;
//                 delete p;
//                 break;
//             }
//             if(i == (cnt + 1 -n))
//             {
//                 q->next = p->next;
//                 delete p;
//                 break;
//             }
//             q = p;
//             p = p->next;
//             i++;
//         }

//         return head;
//     }
// };

class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @param n: An integer.
     * @return: The head of linked list.
     */
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // write your code here
        ListNode *p = head;
        int cnt = 0;
        while(p!=NULL)
        {
            cnt++;
            p = p->next;
        }
        if(cnt == n)
        {
            p = head->next;
            delete head;
            return p;
        }
        p = head;
        int i=2;
        ListNode *prior=head;
        while(p->next!=NULL && i<=cnt-n+1)
        {
            i++;
            prior = p;
            p = p->next;
        }
        prior->next = p->next;
        delete p;
        return head;
    }
};
