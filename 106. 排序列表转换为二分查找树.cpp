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
 */


class Solution {
public:
    /*
     * @param head: The first node of linked list.
     * @return: a tree node
     */
    void listToBST(TreeNode **root, vector<int> &v, int pos1, int pos2)
    {
        if(pos1 <= pos2)
        {
            if(*root==NULL)
            {
                *root = new TreeNode(v[(pos1+pos2)/2]);
                listToBST(&(*root)->left, v, pos1, (pos1+pos2)/2-1);
                listToBST(&(*root)->right, v, (pos1+pos2)/2+1, pos2);
            }
        }
    }
    TreeNode * sortedListToBST(ListNode * head) {
        // write your code here
        vector<int> v;
        while(head!=NULL)
        {
            v.push_back(head->val);
            head = head->next;
        }
        TreeNode *tree = NULL;
        listToBST(&tree, v, 0, v.size()-1);
        return tree;
    }
};
