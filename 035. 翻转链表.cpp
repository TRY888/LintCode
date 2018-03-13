/**
 * Definition of ListNode
 *
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */


// class Solution {
// public:
//     /*
//      * @param head: n
//      * @return: The new head of reversed linked list.
//      */
//     ListNode * reverse(ListNode * head) {
//         // write your code here

// /*      原来的写法：
//         ListNode *newHead = new ListNode(0);
//         newHead->next = NULL;
//         ListNode *p,*temp,*s;
//         p = head;
//         s = newHead->next;
//         while(p!=NULL)
//         {
//             newHead->next = p;
//             temp = p->next;
//             p->next = s;
//             s = p;
//             p = temp;
//         }
//         temp = newHead->next;
//         delete newHead;
//         return temp;
// */
//         //新的写法
//         ListNode *p, *s, *temp;
//         p = head;
//         s = temp = NULL;
//         while(p!=NULL)
//         {
//             temp = p->next;
//             p->next = s;
//             s = p;
//             p = temp;
//         }
//         return s;
//     }
// };

class Solution {
public:
    /*
     * @param head: n
     * @return: The new head of reversed linked list.
     */
    ListNode * reverse(ListNode * head) {
        // write your code here
        ListNode *p, *s, *temp;
        p = head;
        s = NULL;
        while(p!=NULL)
        {
            temp = p->next;
            p->next = s;
            s = p;
            p = temp;
        }
        return s;
    }
};
