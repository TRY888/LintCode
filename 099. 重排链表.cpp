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


class Solution {
public:
    /*
     * @param head: The head of linked list.
     * @return: nothing
     */
    ListNode* reverse(ListNode* head)
    {
        ListNode *p, *s, *temp;
        p = head;
        s = temp = NULL;
        while(p!=NULL)
        {
            temp = p->next;
            p->next = s;
            s = p;
            p = temp;
        }
        return s;
    }

    void reorderList(ListNode * head) {
        // write your code here
        ListNode *p;
        int len;
        p = head;
        len = 0;
        while(p!=NULL)
        {
            p = p->next;
            len++;
        }

        p = head;
        ListNode *s, *q;
        s = NULL;
        for(int i=0; i<(len/2); ++i)
        {
            q = p->next;
            p->next = s;
            s = p;
            p = q;
        }

        q = NULL;
        ListNode *newHead = p;
        ListNode *temp;
        if(len%2 != 0)
            p = p->next;
        while(p!=NULL)
        {
            q = p->next;
            p->next = s;
            temp = s->next;
            s->next= q;
            p = q;
            s = temp;
        }

        head = reverse(newHead);

    }
};
