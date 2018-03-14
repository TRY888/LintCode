/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param headA: the first list
     * @param headB: the second list
     * @return: a ListNode
     */
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // write your code here
        ListNode *pA=headA, *pB=headB;
        ListNode *lastA, *lastB;
        int lenA=0, lenB=0;
        while(pA!=NULL)
        {
            lenA++;
            lastA = pA;
            pA = pA->next;
        }
        while(pB!=NULL)
        {
            lenB++;
            lastB = pB;
            pB = pB->next;
        }
        if(lastA!=lastB)
            return NULL;
        pA = headA;
        pB = headB;
        if(lenA>lenB)
        {
            int i = 0;
            while(pA!=NULL && i<lenA-lenB)
            {
                pA = pA->next;
                i++;
            }
        }
        else
        {
            int i = 0;
            while(pB!=NULL && i<lenB-lenA)
            {
                pB = pB->next;
                i++;
            }
        }
        ListNode *res=NULL;
        while(pA!=NULL && pB!=NULL)
        {
            if(pA == pB)
            {
                res = pA;
                break;
            }
            pA = pA->next;
            pB = pB->next;
        }
        return res;
    }
};
