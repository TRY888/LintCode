/*
 * title：中等-170.旋转链表
 * desc:给定一个链表，旋转链表，使得每个节点向右移动k个位置，其中k是一个非负数
 * e.g.:给出链表1->2->3->4->5->null和k=2 返回4->5->1->2->3->null
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