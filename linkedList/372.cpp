/**
 * title:372.在O(1)时间复杂度删除链表节点
 * desc:给定一个单链表中的一个等待被删除的节点(非表头或表尾)。
 *      请在在O(1)时间复杂度删除该链表节点。
 * e.g.:Linked list is 1->2->3->4, and given node 3, 
 *      delete the node in place 1->2->4
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
     * @param node: a node in the list should be deleted
     * @return: nothing
     */
    void deleteNode(ListNode *node) {
        // write your code here
        node->val = node->next->val;
        node->next = node->next->next;
    }
};