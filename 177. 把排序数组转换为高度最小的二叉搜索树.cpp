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
     * @param A: an integer array
     * @return: A tree node
     */

    // void sortedArrayToBstCore(TreeNode **root, vector<int> &A, int left, int right)
    // {
    //     if(left == right)
    //     {
    //         *root = new TreeNode(A[left]);

    //     }
    //     else if(left < right)
    //     {
    //         int mid = (left + right)/2;
    //         // cout << "left:" <<left << " mid:" << mid << " right:" << right << endl;
    //         *root = new TreeNode(A[mid]);
    //         // cout << root->val << endl;
    //         int new_left = mid - 1;
    //         int new_right = mid + 1;
    //         sortedArrayToBstCore(&((*root)->left), A, left, new_left);
    //         sortedArrayToBstCore(&((*root)->right), A, new_right, right);
    //     }
    // }

    void sortedArrayToBstCore1(TreeNode **root, vector<int> &A, int low, int high)
    {
        if(low<=high)
        {
            int mid = (low+high)/2;
            *root = new TreeNode(A[mid]);
            sortedArrayToBstCore1(&((*root)->left), A, low, mid-1);
            sortedArrayToBstCore1(&((*root)->right), A, mid+1, high);
        }
    }


    TreeNode * sortedArrayToBST(vector<int> &A) {
        // write your code here
        if(A.size() == 0)
            return NULL;
        TreeNode *root = NULL;
        sortedArrayToBstCore1(&root, A, 0, A.size()-1);
        return root;
    }
};
