/*
 * title：中等-511.交换链表当中两个节点
 * desc:给你一个链表以及两个权值v1和v2，交换链表中权值为v1和v2的这两个节点。保证链表中节点权值各不相同，如果没有找到对应节点，那么什么也不用做。
 * e.g.:你需要交换两个节点而不是改变节点的权值
 *      给出链表 1->2->3->4->null ，以及 v1 = 2 ， v2 = 4
 *      返回结果 1->4->3->2->null
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
     * @param head: a ListNode
     * @param v1: An integer
     * @param v2: An integer
     * @return: a new head of singly-linked list
     */
    ListNode * swapNodes(ListNode * head, int v1, int v2) {
        // write your code here
        ListNode *p, *before1, *before2, *node1, *node2, *end1, *end2, *s;
        before1 = before2 = node1 = node2 = end1 = end2 = NULL;
        bool flag1, flag2;
        flag1 = flag2 = false;
        ListNode *newHead = new ListNode(0);
        newHead->next = head; 
        p = head;
        s = newHead;
        while(p!=NULL)
        {
            if(p->val == v1 && flag1 == false)
            {
                before1 = s;
                end1 = p->next;
                node1 = p;
                flag1 = true;
            }
            if(p->val == v2 && flag2 == false)
            {
            	before2 = s;
                end2 = p->next;
                node2 = p;
                flag2 = true;
            }
            if(flag1 == true && flag2 == true)
            	break;
            s = p;
            p = p->next;
        }
        if(node1 == NULL || node2 == NULL)
        	return head;
        if(end1 == node2)
        {
        	before1->next = node2;
        	node2->next= node1;
        	node1->next = end2;
        }
        else if(end2 == node1)
        {
        	before2->next= node1;
        	node1->next = node2;
        	node2->next = end1;
        }
        else
        {
        	before1->next = node2;
			node2->next = end1;
			before2->next = node1;
			node1->next = end2; 
        }
        p = newHead->next;
        delete newHead;
		return p; 
        
    }
};


class Solution {
public:
    /*
     * @param nums: A list of integers
     * @param k: An integer
     * @return: The majority number
     */
    struct ListNode{
        int val;
        int cnt;
        ListNode *next;
        ListNode(int x, int c):val(x), cnt(c), next(NULL){}
    };
    
    void insert(ListNode **head, ListNode **tail, int value, int count)
    {
        if(*head == NULL)
        {
            ListNode *newNode = new ListNode(value, count);
            *tail = newNode;
            *head = newNode;
        }
        else
        {
            ListNode *newNode = new ListNode(value, count);
            (*tail)->next = newNode;
            *tail = newNode;
        }
    }
    
    bool isValueExistInList(ListNode *head, int value)
    {
        ListNode *p = head;
        while(p!=NULL)
        {
            if(p->val == value)
            {
                p->cnt++;
                return true;
            }
            p = p->next;
        }
        return false;
    }
    
    int findMaxValueInList(ListNode *head)
    {
        int value = 0, cnt = -1;
        ListNode *p = head;
        while(p!=NULL)
        {
            if(p->cnt > cnt)
            {
                value = p->val;
                cnt = p->cnt;
            }
            p = p->next;
        }
        return value;
    }
    
    int majorityNumber(vector<int> &nums, int k) {
        // write your code here
        ListNode *tail,*newHead;
        tail = newHead = NULL;
        int size = nums.size();
        for(int i=0; i<size; ++i)
        {
            if(isValueExistInList(newHead, nums[i]) == false)
                insert(&newHead, &tail, nums[i], 1);
        }
        return findMaxValueInList(newHead);
    }
};