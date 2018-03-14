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
// class Solution{
// public:
//     /**
//      * @param head: The first node of linked list.
//      * @return: head node
//      */

//     ListNode * deleteDuplicates(ListNode *head) {
//         // write your code here
//         ListNode *newHead = new ListNode(0);
//         newHead->next = head;
//         ListNode *start = newHead;
//         ListNode *p = head;
//         ListNode *q = NULL;
//         ListNode *s = NULL;
//         ListNode *temp = NULL;
//         bool flag = false;
//         while(p!=NULL)
//         {
//     		q = p->next;
//     		s = p;
//       		while(q!=NULL)
//     		{
//     			temp = q->next;
//     			if(q->val == p->val)
//     			{
//     				s->next= temp;
//     				flag = true;
//     				delete q;
//     			}
//     			else
//     				s = q;
//     			q = temp;
//     		}
//     		temp = p->next;
//     	 	if(flag == true)
//     	 	{
//     	 		start->next = temp;
//     	 		flag = false;
//     	 		delete p;
//     	 	}
//     	 	else
//     	 		start = p;
//     	 	p = temp;
//         }
//         temp = newHead->next;
//         delete newHead;
//         return temp;
//     }
// };

class Solution{
public:
    /**
     * @param head: The first node of linked list.
     * @return: head node
     */

    ListNode * deleteDuplicates(ListNode *head) {
        // write your code here
        map<int, int> m;
        ListNode *p = head;
        while(p!=NULL)
        {
            m[p->val]++;
            p = p->next;
        }
        p = head;
        ListNode *list_head = new ListNode(0);
        list_head->next = head;
        ListNode *prior = list_head;
        ListNode *temp;
        while(p!=NULL)
        {
            if(m[p->val]>1)
            {
                prior->next = p->next;
                temp = p->next;
                free(p);
                p = temp;
            }
            else
            {
                prior = p;
                p = p->next;
            }
        }
        temp = list_head->next;
        delete list_head;
        return temp;
    }
};
