/*
 * title：中等-221.链表求和 II
 * desc:假定用一个链表表示两个数，其中每个节点仅包含一个数字。
 *      假设这两个数的数字顺序排列，请设计一种方法将两个数相加，
 *      并将其结果表现为链表的形式。
 * e.g.:给出 6->1->7 + 2->9->5。即，617 + 295。
 *      返回 9->1->2。即，912
 */

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
     * @param l1: The first list.
     * @param l2: The second list.
     * @return: the sum list of l1 and l2.
     */
     
    ListNode *reverse(ListNode *head)
	{
		ListNode *newHead = new ListNode(0);
		newHead->next = NULL;
		ListNode *p, *s, *temp;
		p = head;
		s = newHead->next;
		while(p!=NULL)
		{
			newHead->next= p;
			temp = p->next;
			p->next = s;
			s = p;
			p = temp;	
		} 
		temp = newHead->next;
		delete newHead;
		return temp;
 	} 
 	void insert(ListNode *tail, int x)
 	{
 		ListNode *node = new ListNode(x);
 		node->next = NULL;
 		tail->next = node;
 		tail = node;
 	}
 	
    ListNode * addLists2(ListNode * l1, ListNode * l2) {
        // write your code here
        ListNode *L1,*L2;
        ListNode *newHead = new ListNode(0);
        newHead->next = NULL;
        ListNode *tail = newHead;
        ListNode *temp;
        L1 = reverse(l1);
        L2 = reverse(l2);
        int result = 0;
        int x = 0;
        while(1)
        {
        	if((L1==NULL) && (L2==NULL))
        	{
        		if(x>0)
        		{
		        	insert(tail, 1);
		        	break;
		        }
		        else
		        	break;
	        }
	        if((L1 != NULL) && (L2 == NULL))
	        {
	        	result = L1->val + x;
	        	x = 0;
	        	if(result >= 10)
	        	{
	        		result = result - 10;
	        		x = 1;	
	        	}
				insert(tail, result);
        	}
        	if((L1 == NULL) && (L2 != NULL))
        	{
	        	result = L2->val + x;
	        	x = 0;
	        	if(result >= 10)
	        	{
	        		result = result - 10;
	        		x = 1;	
	        	}
				insert(tail, result);
	        }
	        if((L1 != NULL) && (L2 != NULL))
	        {
        		result = L1->val+ L2->val + x;
        		x = 0;
        		if(result >= 10)
        		{
		        	result = result - 10;
	        		x = 1;	
		        }
		        insert(tail, result);
        	}
        }
        temp = newHead->next;
        delete newHead; 
        

        return reverse(temp);
    }
};