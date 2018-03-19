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
     * @param root: The root of binary tree
     * @return: root of new tree
     */
    TreeNode * cloneTree(TreeNode * root) {
        // write your code here
        TreeNode *clone_root = NULL;
        if(root!=NULL)
        {
            clone_root = new TreeNode(root->val);
            cloneTreeCore(root, clone_root);
        }
        return clone_root;
    }
    void cloneTreeCore(TreeNode *root, TreeNode *clone)
    {
        if(root->left == NULL && root->right == NULL)
        {
            return;
        }
        if(root->left!=NULL)
        {
            clone->left = new TreeNode(root->left->val);
            cloneTreeCore(root->left, clone->left);
        }
        if(root->right!=NULL)
        {
            clone->right = new TreeNode(root->right->val);
            cloneTreeCore(root->right, clone->right);
        }
    }
};
