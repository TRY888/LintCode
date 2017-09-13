/*
 * title：困难-103.带环链表 II
 * desc:给定一个链表，如果链表中存在环，则返回到链表中环的起始节点的值，如果没有环，返回null。
 * e.g.:给出 -21->10->4->5, tail connects to node index 1，返回10
 *      不使用额外的空间
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
     * @return: The node where the cycle begins. 
     *           if there is no cycle, return null
     */
    bool isPointerExist(ListNode *head, ListNode *pointer)
    {
    	ListNode *p = head;
    	if(p == NULL)
    		return false;
    	else
    	{
    		while(p!=NULL)
    		{
    			if(p == pointer)
    				return true;
    			p = p->next;
    		}
    		return false;
    	}
    }
    ListNode *detectCycle(ListNode *head) {
        // write your code here
        ListNode *p, *s, *temp;
    	p = head;
    	s = temp = NULL;
    	while(p!=NULL)
    	{
    		if(isPointerExist(s, p) == true)
    		{
			    p->next= NULL;
			    return p;
		    }
    		else
    		{
    			temp = p->next;
    			p->next = s;
    			s = p;
    			p = temp;
    		}
    	}
    	return NULL; 
    }
   //首先，利用快慢指针判断有无环，若遇到slow == fast时，跳出循环；
   //然后，调整fast=head，slow不变，此时slow与fast同步移动，直至再次相遇，即是
   //表中环的起始节点。

/*   ListNode *detectCycle(ListNode *head) {
        // write your code here
       if(head == NULL || head->next ==NULL)  
        {  
            return NULL;  
        }//if  
          
        ListNode *slow = head, *fast = head;  
        while(fast && fast->next)  
        {  
            slow = slow->next;  
            fast = fast->next->next;  
            if(slow == fast)  
            {  
                break;  
            }//if  
        }//while  
          
        if(fast && fast == slow)  
        {  
            fast = head;  
            while(fast != slow)  
            {  
                fast = fast->next;  
                slow = slow->next;  
            }//while  
              
            return fast;  
        }//if  
        return NULL;  
    }
    */
};


