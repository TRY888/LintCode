/*
 * title：中等-113.删除排序链表中的重复数字 II
 * desc:给定一个排序链表，删除所有重复的元素只留下原链表中没有重复的元素。
 * e.g.:给出 1->2->3->3->4->4->5->null，返回 1->2->5->null
 *      给出 1->1->1->2->3->null，返回 2->3->null
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
class Solution{
public:
    /**
     * @param head: The first node of linked list.
     * @return: head node
     */

    ListNode * deleteDuplicates(ListNode *head) {
        // write your code here
        ListNode *newHead = new ListNode(0);
        newHead->next = head;
        ListNode *start = newHead;
        ListNode *p = head;
        ListNode *q = NULL;
        ListNode *s = NULL;
        ListNode *temp = NULL;
        bool flag = false;
        while(p!=NULL)
        {
    		q = p->next;
    		s = p;
       		while(q!=NULL)
    		{
    			temp = q->next;
    			if(q->val == p->val)
    			{
    				s->next= temp;
    				flag = true;
    				delete q;
    			}
    			else
    				s = q;
    			q = temp;
    		}
    		temp = p->next;
    	 	if(flag == true)
    	 	{
    	 		start->next = temp;
    	 		flag = false;
    	 		delete p;
    	 	}
    	 	else
    	 		start = p;
    	 	p = temp;
        }
        temp = newHead->next;
        delete newHead;
        return temp;
    }
};