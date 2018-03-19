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
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */

    // 递归法超级简单
    // void invertBinaryTree(TreeNode * root) {
    //     // write your code here
    //     if(root!=NULL)
    //     {
    //         TreeNode *left = root->left;
    //         TreeNode *right = root->right;
    //         root->left = right;
    //         root->right = left;
    //         invertBinaryTree(left);
    //         invertBinaryTree(right);
    //     }
    // }
    // 非递归法（采用层次遍历的方法）
    void invertBinaryTree(TreeNode *root)
    {
        queue<TreeNode *> q;
        int cnt,count;
        cnt = count = 0;
        if(root!=NULL)
        {
            q.push(root);
            cnt = 1;
            count = 0;
            while(root!=NULL)
            {
                while(cnt>0)
                {
                    cnt--;
                    TreeNode *temp = q.front();
                    q.pop();
                    TreeNode *left = temp->left;
                    TreeNode *right = temp->right;
                    temp->left = right;
                    temp->right = left;
                    if(left!=NULL)
                    {
                        q.push(left);
                        count++;
                    }
                    if(right!=NULL)
                    {
                        q.push(right);
                        count++;
                    }
                }
                cnt = count;
                count=0;
                if(q.empty())
                    root = NULL;
                else
                    root = q.front();
            }
        }
    }
};
