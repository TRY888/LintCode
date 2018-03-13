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
//     /*
//      * @param head: The first node of linked list
//      * @param x: An integer
//      * @return: A ListNode
//      */
//     ListNode * partition(ListNode * head, int x) {
//         // write your code here
//         ListNode *one = new ListNode(0);
//         ListNode *two = new ListNode(0);
//         one->next = NULL;
//         two->next = NULL;
//         ListNode *ptOne = one;
//         ListNode *ptTwo = two;
//         ListNode *original = head;
//         ListNode *temp;
//         while(original != NULL)
//         {
//             if(original->val < x)
//             {
//                 ptOne->next = original;
//                 ptOne = original;
//             }
//             else
//             {
//                 ptTwo->next = original;
//                 ptTwo = original;
//             }
//             original = original->next;
//         }
//         ptOne->next = two->next;
//         ptTwo->next = NULL;
//         temp = one->next;
//         delete one;
//         delete two;
//         return temp;


//     }
// };

class Solution {
public:
    /*
     * @param head: The first node of linked list
     * @param x: An integer
     * @return: A ListNode
     */
    ListNode * partition(ListNode * head, int x) {
        // write your code here
        ListNode *A = new ListNode(0);
        ListNode *B = new ListNode(0);
        ListNode *p = head, *pA=A, *pB=B, *temp;
        while(p!=NULL)
        {
            temp = p->next;
            if(p->val < x)
            {
                pA->next = p;
                p->next = NULL;
                pA = pA->next;
            }
            else
            {
                pB->next = p;
                p->next = NULL;
                pB = pB->next;
            }
            p = temp;
        }
        pA->next = B->next;
        delete B;
        temp = A->next;
        delete A;
        return temp;


    }
};
