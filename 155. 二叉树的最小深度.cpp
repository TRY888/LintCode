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
     * @return: An integer
     */

    int minDepth(TreeNode * root) {
        // write your code here
        queue<TreeNode *> q;
        int cnt1 = 0, cnt2 = 0;
        int high = 0;
        if(root==NULL)
            return 0;
        else
        {
            q.push(root);
            cnt1++;
            cnt2 = 0;
        }
        while(q.size())
        {
            high++;
            while(cnt1 > 0)
            {
                cnt1--;
                TreeNode *temp = q.front();
                q.pop();
                if(temp->left!=NULL)
                {
                    q.push(temp->left);
                    cnt2++;
                }
                if(temp->right!=NULL)
                {
                    q.push(temp->right);
                    cnt2++;
                }
                if(temp->left==NULL && temp->right==NULL)
                {
                    return high;
                }
            }
            cnt1 = cnt2;
            cnt2 = 0;
        }
        return high;
    }
};
