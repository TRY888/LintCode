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
    /**
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int maxDepth(TreeNode *root) {
        // write your code here
        int h1,h2,h;
        if(root==NULL)
            return 0;
        else
        {
            h1 = maxDepth(root->left);
            h2 = maxDepth(root->right);
            if(h1>h2)
                h = h1 + 1;
            else
                h = h2 + 1;
            return h;
        }
    }
};
