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
     * @param head: the list
     * @param k: rotate to the right k places
     * @return: the list after rotation
     */
    ListNode *rotateRight(ListNode *head, int k) {
        // write your code here
        if(k == 0)
            return head;
        ListNode *p, *s, *temp;
        int len,cnt,x;
        len = cnt = 0;
        p = head;
        while(p!=NULL)
        {
            p = p->next;
            len++;
        }
        if(len == 0)
            return head;
        x = len - k%len + 1;
        if(x == (len+1) || x == 1)
            return head;
        p = head;
        s = NULL;
        while(p!=NULL)
        {
            cnt++;
            if(cnt == x)
            {
                s->next= NULL;
                break;
            }
            s = p;
            p = p->next;
        }
        temp = p;
        while(p!=NULL)
        {
            s = p;
            p = p->next;
        }
        s->next = head;
        return temp;
    }
};

