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


// class Solution {
// public:
//     /*
//      * @param head: ListNode head is the head of the linked list
//      * @param m: An integer
//      * @param n: An integer
//      * @return: The head of the reversed ListNode
//      */
//     ListNode * reverseBetween(ListNode * head, int m, int n) {
//         // write your code here
//         if(m == n)
// 		return head;
//     	ListNode *newHead = new ListNode(0);
//     	newHead->next = head;
//     	ListNode *p, *s, *temp, *start, *end;
//     	int cnt = 0;
//      	p = head;
//      	s = temp = end = NULL;
//      	start = newHead;
//     	while(p!=NULL)
//     	{
//     		cnt++;
//     		if(cnt == m)
//     		{
//     			end = p;

//     			temp = p->next;
//     			p->next= s;
//     			s = p;
//     			p = temp;

//     			break;
//     		}
//     		start = p;
//     		p = p->next;
//     	}

//     	while(p!=NULL)
//     	{
//     		cnt++;
//     		temp = p->next;
//     		p->next= s;
//     		s = p;
//     		p = temp;
//     		if(cnt == n)
//     			break;
//     	}
//     	start->next = s;
//     	end->next = p;
//     	temp = newHead->next;
//     	delete newHead;
//     	return temp;
//     }
// };

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
        ListNode *prior, *p, *start, *end, *s, *temp;
        prior = NULL;
        p = head;
        s = NULL;
        int i=1;
        while(p!=NULL && i<m)
        {
            prior = p;
            p = p->next;
            i++;
        }
        end = p;
        while(p!=NULL && i<n)
        {
            i++;
            temp = p->next;
            p->next = s;
            s = p;
            p = temp;
        }
        start = p;
        temp = p->next;
        p->next = s;

        if(prior == NULL)
        {
            end->next = temp;
            return start;
        }
        else
        {
            prior->next = start;
            end->next = temp;
            return head;
        }
    }
};
