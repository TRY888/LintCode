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
//      * @return: head node
//      */
//     ListNode *deleteDuplicates(ListNode *head) {
//         // write your code here
//         if(head == NULL)
//             return NULL;
//         ListNode *p = head;
//         ListNode *q = head;
//         int x = p->val;
//         ListNode *temp;
//         p = p->next;
//         while(p != NULL)
//         {
//             if(p->val == x)
//             {
//                 temp = p;
//                 q->next = p->next;
//                 p = p->next;
//                 delete temp;
//             }
//             else
//             {
//                 x = p->val;
//                 q = p;
//                 p = p->next;
//             }
//         }
//         return head;
//     }
// };

class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: head node
     */
    ListNode *deleteDuplicates(ListNode *head) {
        // write your code here
        if(head == NULL)
            return NULL;
        ListNode *p = head->next;
        ListNode *prior = head;
        int cmp = head->val;
        while(p!=NULL)
        {
            if(p->val == cmp)
            {
                ListNode *temp = p->next;
                prior->next = temp;
                delete p;
                p = temp;
            }
            else
            {
                cmp = p->val;
                prior = p;
                p = p->next;
            }
        }
        return head;
    }
};
