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
//      * @param v1: An integer
//      * @param v2: An integer
//      * @return: a new head of singly-linked list
//      */
//     ListNode * swapNodes(ListNode * head, int v1, int v2) {
//         // write your code here
//         ListNode *p, *before1, *before2, *node1, *node2, *end1, *end2, *s;
//         before1 = before2 = node1 = node2 = end1 = end2 = NULL;
//         bool flag1, flag2;
//         flag1 = flag2 = false;
//         ListNode *newHead = new ListNode(0);
//         newHead->next = head;
//         p = head;
//         s = newHead;
//         while(p!=NULL)
//         {
//             if(p->val == v1 && flag1 == false)
//             {
//                 before1 = s;
//                 end1 = p->next;
//                 node1 = p;
//                 flag1 = true;
//             }
//             if(p->val == v2 && flag2 == false)
//             {
//             	before2 = s;
//                 end2 = p->next;
//                 node2 = p;
//                 flag2 = true;
//             }
//             if(flag1 == true && flag2 == true)
//             	break;
//             s = p;
//             p = p->next;
//         }
//         if(node1 == NULL || node2 == NULL)
//         	return head;
//         if(end1 == node2)
//         {
//         	before1->next = node2;
//         	node2->next= node1;
//         	node1->next = end2;
//         }
//         else if(end2 == node1)
//         {
//         	before2->next= node1;
//         	node1->next = node2;
//         	node2->next = end1;
//         }
//         else
//         {
//         	before1->next = node2;
// 			node2->next = end1;
// 			before2->next = node1;
// 			node1->next = end2;
//         }
//         p = newHead->next;
//         delete newHead;
// 		return p;

//     }
// };

class Solution {
public:
    /*
     * @param head: a ListNode
     * @param v1: An integer
     * @param v2: An integer
     * @return: a new head of singly-linked list
     */
    ListNode * swapNodes(ListNode * head, int v1, int v2) {
        // write your code here
        ListNode *listHead = new ListNode(0);
        listHead->next = head;
        ListNode *p, *prior1, *next1, *prior2, *next2, *prior, *p1, *p2;
        p = head;
        p1 = p2 = NULL;
        prior = listHead;
        while(p!=NULL)
        {
            if(p->val == v1)
            {
                prior1 = prior;
                next1 = p->next;
                p1 = p;
            }
            if(p->val == v2)
            {
                prior2 = prior;
                next2 = p->next;
                p2 = p;
            }
            prior = p;
            p = p->next;
        }
        if(p1 == NULL || p2 == NULL)
        {
            delete listHead;
            return head;
        }
        if(p1->next == p2)
        {
            prior1->next = p2;
            p2->next = p1;
            p1->next = next2;
        }
        else if(p2->next == p1)
        {
            prior2->next = p1;
            p1->next = p2;
            p2->next = next1;
        }
        else
        {
            prior1->next = p2;
            p2->next = next1;
            prior2->next = p1;
            p1->next = next2;
        }
        p = listHead->next;
        delete listHead;
        return p;
    }
};
