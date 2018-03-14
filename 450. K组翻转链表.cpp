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
    /*
     * @param head: a ListNode
     * @param k: An integer
     * @return: a ListNode
     */

    ListNode *reverse(ListNode *start, ListNode *end)
    {
        ListNode *p, *s, *temp;
        p = start;
        s = end;
        temp = NULL;
        while(p!=NULL && p!=end)
        {
            temp = p->next;
            p->next = s;
            s = p;
            p = temp;
        }
        return s;
    }

    ListNode * reverseKGroup(ListNode * head, int k) {
        // write your code here
        if(k==1)
            return head;
        ListNode *p, *s, *temp, *start, *end, *temp_start;
        int cnt;
        cnt = 0;
        p = head;
        start = head;
        temp_start = start;
        bool flag = true;
        while(p!=NULL)
        {
            cnt++;
            temp = p->next;
            if(cnt == k)
            {
                cnt = 0;
                end = p->next;
                ListNode *newHead = reverse(start, end);
                if(flag == true)
                {
                    head = newHead;
                    flag = false;
                }
                else
                {
                    temp_start->next= p;
                }
                temp_start = start;
                start = temp;
            }
            p = temp;
        }
        return head;
    }
};
