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
//     /**
//      * @param l1: the first list
//      * @param l2: the second list
//      * @return: the sum list of l1 and l2
//      */
//     int insert(ListNode **head, ListNode **tail, int x)
//     {
//         ListNode *temp;
//         if(*head == NULL || *tail == NULL)
//         {
//             temp = (ListNode *)malloc(sizeof(ListNode));
//             if(temp != NULL)
//             {
//                 temp->val = x;
//                 temp->next = NULL;
//                 *head = *tail = temp;
//                 return 1;
//             }
//         }
//         else
//         {
//             temp = (ListNode *)malloc(sizeof(ListNode));
//             if(temp != NULL)
//             {
//                 temp->val = x;
//                 temp->next = NULL;
//                 (*tail)->next = temp;
//                 *tail = temp;
//                 return 1;
//             }
//         }
//         return 0;

//     }
//     ListNode *addLists(ListNode *l1, ListNode *l2) {
//         // write your code here
//         ListNode *L1, *L2, *head, *tail;
//         int sum, x, val1, val2;
//         val1 = val2 = 0;
//         sum = x =0;
//         L1 = l1;
//         L2 = l2;
//         head = tail = NULL;
//         while(1)
//         {
//             if(L1 == NULL && L2 == NULL)
//             {
//                 if(x == 1)
//                     insert(&head, &tail, x);
//                 break;
//             }
//             else if(L1 == NULL && L2 != NULL)
//             {
//                 val1 = 0;
//                 val2 = L2->val;
//                 L2 = L2->next;
//             }
//             else if(L1 != NULL && L2 == NULL)
//             {
//                 val1 = L1->val;
//                 val2 = 0;
//                 L1 = L1->next;
//             }
//             else
//             {
//                 val1 = L1->val;
//                 val2 = L2->val;
//                 L1 = L1->next;
//                 L2 = L2->next;
//             }

//             sum = val1 + val2 + x;
//             x = 0;
//             if(sum >= 10)
//             {
//                 x = 1;
//                 sum = sum - 10;
//             }
//             insert(&head, &tail, sum);
//         }
//         return head;
//     }
// };

class Solution {
public:
    /**
     * @param l1: the first list
     * @param l2: the second list
     * @return: the sum list of l1 and l2
     */

    ListNode *addLists(ListNode *l1, ListNode *l2) {
        // write your code here
        ListNode *l3 = new ListNode(0);
        ListNode *p1=l1, *p2=l2, *p3=l3;
        int add = 0;
        while(p1!=NULL || p2!=NULL)
        {
            int sum = 0;
            if(p1 == NULL && p2 != NULL)
            {
                sum = p2->val + add;
                add = 0;
                p2 = p2->next;
            }
            if(p1 != NULL && p2 == NULL)
            {
                sum = p1->val + add;
                add = 0;
                p1 = p1->next;
            }
            if(p1 !=NULL && p2 != NULL)
            {
                sum = p1->val + p2->val + add;
                add = 0;
                p1 = p1->next;
                p2 = p2->next;
            }
            if(sum>=10)
            {
                sum = sum - 10;
                add = 1;
            }
            ListNode *temp = new ListNode(sum);
            p3->next = temp;
            p3 = p3->next;
        }
        if(add != 0)
        {
            ListNode *temp = new ListNode(add);
            p3->next = temp;
            p3 = p3->next;
        }

        ListNode *temp = l3->next;
        delete l3;
        return temp;
    }
};
