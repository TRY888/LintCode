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
     * @param val: An integer
     * @return: a ListNode
     */
    ListNode * removeElements(ListNode * head, int val) {
        // write your code here
        ListNode *head_node = new ListNode(0);
        head_node->next = head;
        ListNode *p = head_node;
        while(p->next!=NULL)
        {
            if(p->next->val == val)
            {
                ListNode *temp = p->next;
                p->next = temp->next;
                free(temp);
            }
            else
                p = p->next;
        }
        ListNode *new_head = head_node->next;
        delete head_node;
        return new_head;
    }
};
