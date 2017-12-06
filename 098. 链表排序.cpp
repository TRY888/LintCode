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
     /*
      * @param head: The head of linked list.
      * @return: You should return the head of the sorted linked list, using constant space complexity.
      */
     struct cmp{
         bool operator() (ListNode *a, ListNode *b){
             return (a->val>=b->val);
         }
     };
     ListNode * sortList(ListNode * head) {
         // write your code here
         priority_queue<ListNode *, vector<ListNode *>, cmp> pq;
         while(head!=NULL)
         {
             ListNode *temp = head->next;
             head->next = NULL;
             pq.push(head);
             head = temp;
         }

         ListNode *newHead = new ListNode(0);
         ListNode *temp = newHead;
         while(pq.size()>0)
         {
             temp->next = pq.top();
             pq.pop();
             temp = temp->next;
         }
         temp = newHead->next;
         delete newHead;
         return temp;
     }
 };
