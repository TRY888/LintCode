/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 * Definition of Doubly-ListNode
 * class DoublyListNode {
 * public:
 *     int val;
 *     DoublyListNode *next, *prev;
 *     DoublyListNode(int val) {
 *         this->val = val;
           this->prev = this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param root: The root of tree
     * @return: the head of doubly list node
     */
    DoublyListNode *temp;
    void core(TreeNode *root)
    {
        if(root!=NULL)
        {
            core(root->left);
            DoublyListNode *new_node = new DoublyListNode(root->val);
            temp->next = new_node;
            new_node->prev = temp;
            temp = new_node;
            core(root->right);
        }
    }
    DoublyListNode* bstToDoublyList(TreeNode* root) {
        // Write your code here
        if(root==NULL)
            return NULL;
        DoublyListNode *head = new DoublyListNode(0);
        temp = head;
        core(root);
        temp = head->next;
        temp->prev = NULL;
        delete head;
        return temp;
    }
};
