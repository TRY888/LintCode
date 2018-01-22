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
 */


class Solution {
public:
    /*
     * @param root: The root of binary tree.
     * @return: True if this Binary tree is Balanced, or false.
     */

    int treeHigh(TreeNode *root, bool &ok)
    {
        if(root == NULL)
            return 0;
        int left = treeHigh(root->left, ok);
        int right = treeHigh(root->right, ok);
        if(abs(left-right)>=2)
            ok = false;
        if(left>=right)
        {
            left++;
            return left;
        }
        else
        {
            right++;
            return right;
        }
    }

    bool isBalanced(TreeNode * root) {
        // write your code here
        bool ok = true;
        treeHigh(root, ok);
        return ok;

    }
};
