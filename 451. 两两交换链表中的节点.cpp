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
//      * @param head: a ListNode
//      * @return: a ListNode
//      */
//     ListNode * swapPairs(ListNode * head) {
//         // write your code here
//         ListNode *p,*q, *temp, *newHead,*tempq;
//         tempq = new ListNode(0);
//         tempq->next = NULL;
//         p = head;
//         if(p == NULL)
//             return NULL;
//         q = head->next;
//         newHead = q;
//         if(q == NULL)
//             return p;
//         while((p != NULL) && (q != NULL))
//         {
//         	tempq->next = q;
//             temp = q->next;
//             q->next = p;
//             p->next = temp;
//             tempq = p;
//             p = temp;
//             if(p == NULL)
//                 break;
//             q = temp->next;
//         }

//         return newHead;
//     }
// };

class Solution {
public:
    /*
     * @param head: a ListNode
     * @return: a ListNode
     */
    ListNode * swapPairs(ListNode * head) {
        // write your code here
        if(head==NULL)
            return NULL;
        if(head!=NULL && head->next == NULL)
            return head;
        ListNode *list_head = new ListNode(0);
        list_head->next = head;
        ListNode *prior, *p;
        prior = list_head;
        p = head;
        while(p!=NULL)
        {
            if(p->next!=NULL)
            {
                ListNode *temp = p->next->next;
                prior->next = p->next;
                p->next->next = p;
                p->next = temp;
                prior = p;
            }
            p = p->next;
        }
        ListNode *temp = list_head->next;
        delete list_head;
        return temp;
    }
};
