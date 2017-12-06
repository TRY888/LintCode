class Solution {
public:
    /*
     * @param : the given tree
     * @return: Whether it is a full tree
     */
    bool isFullTree(TreeNode * root) {
        // write your code here
        if((root->left==NULL && root->right!=NULL) || (root->left!=NULL && root->right==NULL))
            return false;
        if(root->left==NULL && root->right==NULL)
            return true;
        if(isFullTree(root->left) == false)
            return false;
        if(isFullTree(root->right) == false)
            return false;
        return true;
    }
};
