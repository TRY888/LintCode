/*
 * title：中等-36.翻转链表 II
 * desc:翻转链表中第m个节点到第n个节点的部分
 *      注意事项
 *      m，n满足1 ≤ m ≤ n ≤ 链表长度
 * e.g.:给出链表1->2->3->4->5->null， m = 2 和n = 4，返回1->4->3->2->5->null

/**
 * Definition of singly-linked-list:
 * 
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */


class Solution {
public:
    /*
     * @param head: ListNode head is the head of the linked list 
     * @param m: An integer
     * @param n: An integer
     * @return: The head of the reversed ListNode
     */
    ListNode * reverseBetween(ListNode * head, int m, int n) {
        // write your code here
        if(m == n)
		return head;
    	ListNode *newHead = new ListNode(0);
    	newHead->next = head;
    	ListNode *p, *s, *temp, *start, *end;
    	int cnt = 0;
     	p = head;
     	s = temp = end = NULL;
     	start = newHead;
    	while(p!=NULL)
    	{
    		cnt++;
    		if(cnt == m)
    		{
    			end = p;
    			
    			temp = p->next;
    			p->next= s;
    			s = p;
    			p = temp;
    		
    			break;
    		}
    		start = p;
    		p = p->next;
    	} 
    	
    	while(p!=NULL)
    	{
    		cnt++;
    		temp = p->next;
    		p->next= s;
    		s = p;
    		p = temp;
    		if(cnt == n)
    			break;
    	}
    	start->next = s;
    	end->next = p;
    	temp = newHead->next;
    	delete newHead;
    	return temp;
    }
};