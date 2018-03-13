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
//      * @param ListNode l1 is the head of the linked list
//      * @param ListNode l2 is the head of the linked list
//      * @return: ListNode head of linked list
//      */
//     ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
//         // write your code here
//         ListNode *newHead, *s, *p, *q, *temp;
//         newHead = new ListNode(0);
//         newHead->next = l1;
//         p = l2;
//         while(p != NULL)
//         {
//             s = newHead;
//             q = newHead->next;
//             while((q != NULL) && (p->val>q->val))
//             {
//                 s = q;
//                 q = q->next;
//             }
//             s->next = p;
//             temp = p->next;
//             p->next = q;
//             p = temp;
//         }
//         temp = newHead->next;
//         delete newHead;
//         newHead = NULL;
//         return temp;

//     }
// };

class Solution {
public:
    /**
     * @param ListNode l1 is the head of the linked list
     * @param ListNode l2 is the head of the linked list
     * @return: ListNode head of linked list
     */
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // write your code here
        ListNode *list_head = new ListNode(0);
        ListNode *p1, *p2, *p3, *temp;
        p1 = l1;
        p2 = l2;
        p3 = list_head;
        while(p1!=NULL || p2!=NULL)
        {
            if(p1!=NULL && p2!=NULL)
            {
                if(p1->val <= p2->val)
                {
                    p3->next = p1;
                    p3 = p3->next;
                    temp = p1->next;
                    p1->next = NULL;
                    p1 = temp;
                }
                else
                {
                    p3->next = p2;
                    p3 = p3->next;
                    temp = p2->next;
                    p2->next = NULL;
                    p2 = temp;
                }
            }
            if(p1==NULL && p2!=NULL)
            {
                p3->next = p2;
                break;
            }
            if(p1!=NULL && p2==NULL)
            {
                p3->next = p1;
                break;
            }
        }
        temp = list_head->next;
        delete list_head;
        return temp;
    }
};
