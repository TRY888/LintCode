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
// class Solution {
// public:
//     /**
//      * @param head: The first node of linked list.
//      * @return: The node where the cycle begins.
//      *           if there is no cycle, return null
//      */

//   //首先，利用快慢指针判断有无环，若遇到slow == fast时，跳出循环；
//   //然后，调整fast=head，slow不变，此时slow与fast同步移动，直至再次相遇，即是
//   //表中环的起始节点。

//   ListNode *detectCycle(ListNode *head) {
//         // write your code here
//       if(head == NULL || head->next ==NULL)
//         {
//             return NULL;
//         }

//         ListNode *slow = head, *fast = head;
//         while(fast && fast->next)
//         {
//             slow = slow->next;
//             fast = fast->next->next;
//             if(slow == fast)
//             {
//                 break;
//             }
//         }

//         if(fast && fast == slow)
//         {
//             fast = head;
//             while(fast != slow)
//             {
//                 fast = fast->next;
//                 slow = slow->next;
//             }
//             return fast;
//         }
//         return NULL;
//     }
// };

class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: The node where the cycle begins.
     *           if there is no cycle, return null
     */

   //首先，利用快慢指针判断有无环，若遇到slow == fast时，跳出循环；
   //然后，调整fast=head，slow不变，此时slow与fast同步移动，直至再次相遇，即是
   //表中环的起始节点。

   ListNode *detectCycle(ListNode *head) {
        // write your code here
        if(head==NULL || head->next==NULL)
            return NULL;
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow)
                break;
        }
        if(fast != NULL && fast == slow)
        {
            fast = head;
            while(fast!=slow)
            {
                fast = fast->next;
                slow = slow->next;
            }
            return fast;
        }
        return NULL;
    }
};

