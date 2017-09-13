/*
 * title：中等-104.合并k个排序链表
 * desc:合并k个排序链表，并且返回合并后的排序链表。尝试分析和描述其复杂度。
 * e.g.:给出3个排序链表[2->4->null,null,-1->null]，返回 -1->2->4->null
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
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    ListNode *merge(vector<ListNode *> &lists)
    {
        int size = lists.size();
        if(size == 0)
            return NULL;
        else if(size == 1)
            return lists[0];
        else
        {
            ListNode *p, *temp;
            p = temp = NULL;
            for(int i=size-2; i>=0; --i)
            {
                p = lists[i];
                if(p == NULL)
                    lists[i] = lists[i+1];
                else
                {
                    while(p!=NULL)
                    {
                        temp = p;
                        p = p->next;
                    }
                    temp->next = lists[i+1];
                }
            }
            return lists[0];
        }
    }
    
    ListNode *insertSort(ListNode *head)
    {
        ListNode *newHead = new ListNode(0);
        ListNode *p, *s, *q, *temp;
        p = head;
        s = newHead;
        q = newHead->next;
        while(p!=NULL)
        {
            s = newHead;
            q = newHead->next;
            if(q == NULL)
            {
                s->next = p;
                temp = p->next;
                p->next = q;
                
            }
            else
            {
                while(q!=NULL)
                {
                    if(p->val > q->val)
                    {
                        s = q;
                        q = q->next;
                        if(q == NULL)
                        {
                            s->next = p;
                            temp = p->next;
                            p->next = NULL;
                            break;
                        }
                    }
                    else
                    {
                        s->next = p;
                        temp = p->next;
                        p->next = q;
                        
                        break;
                        
                    }
                }
            }
            
            p = temp;
        }
        temp = newHead->next;
        delete newHead;
        return temp;
    }
    
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // write your code here
        ListNode *newList = merge(lists);
        return insertSort(newList);
    }
};


