/**
 * title:173.链表插入排序
 * desc:用插入排序对链表排序
 * e.g.:Given 1->3->2->0->null, return 0->1->2->3->null
 */

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
    /**
     * @param head: The first node of linked list.
     * @return: The head of linked list.
     */
    ListNode *insertionSortList(ListNode *head) {
        // write your code here
        ListNode *p,*s,*q;
        p = head->next;
        s = head;
        q = head;
        while(p != NULL)
        {
        	s = head;
        	q = head;	
			while((q != NULL) && (p->val > q->val))
			{
				s = q;
				q = q->next;
			}
			s->next = p;
			p->next = q;		
        	p = p->next;
        }
        return head;
    }
};