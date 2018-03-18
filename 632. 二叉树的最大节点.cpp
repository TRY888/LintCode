class Solution {
public:
    /*
     * @param root: the root of tree
     * @return: the max node
     */

    // 递归方法
    TreeNode* traverse1(TreeNode *root)
    {
        TreeNode *temp1, *temp2;
        if(root==NULL)
        {
            return NULL;
        }
        else
        {
            temp1 = traverse1(root->left);;
            if(temp1!=NULL)
            {
                if(temp1->val < root->val)
                    temp1 = root;
            }
            else
            {
                temp1 = root;
            }
            temp2 = traverse1(root->right);
            if(temp2!=NULL)
            {
                if(temp1->val<temp2->val)
                    temp1 = temp2;
            }
            return temp1;
        }
    }
    // 非递归法(采用中序遍历)
    TreeNode* traverse2(TreeNode *root)
    {
        stack<TreeNode *> s;
        TreeNode *temp2 = NULL;
        int temp_val = INT_MIN;
        while(root!=NULL)
        {
            s.push(root);
            root = root->left;
            if(root == NULL)
            {
                while(!s.empty())
                {
                    TreeNode *temp = s.top();
                    s.pop();
                    if(temp->val >= temp_val)
                    {
                        temp2 = temp;
                        temp_val = temp2->val;
                    }
                    if(temp->right != NULL)
                    {
                        root = temp->right;
                        break;
                    }
                }
            }
        }
        return temp2;
    }
    // 非递归法(采用前序遍历)
    TreeNode *treverse3(TreeNode *root)
    {
        stack<TreeNode *> s;
        TreeNode *temp = NULL;
        int temp_val = INT_MIN;
        while(root!=NULL)
        {
            if(root->val > temp_val)
            {
                temp = root;
                temp_val = temp->val;
            }
            s.push(root);
            root = root->left;
            if(root == NULL)
            {
                while(!s.empty())
                {
                    TreeNode *temp1 = s.top();
                    s.pop();
                    if(temp1->right!=NULL)
                    {
                        root = temp1->right;
                        break;
                    }
                }
            }
        }
        return temp;
    }
    // 非递归法(采用后序遍历)
    TreeNode* traverse4(TreeNode *root)
    {
        stack<TreeNode *> s1;
        stack<bool> s2;
        TreeNode *temp = NULL;
        int temp_val = INT_MIN;
        while(root!=NULL)
        {
            s1.push(root);
            s2.push(false);
            root = root->left;
            if(root == NULL)
            {
                while(!s1.empty())
                {
                    TreeNode *temp1 = s1.top();
                    int num = s2.top();
                    s2.pop();
                    if(num == false)
                    {
                        if(temp1->right == NULL)
                        {
                            if(temp1->val > temp_val)
                            {
                                temp = temp1;
                                temp_val = temp->val;
                            }
                            s1.pop();
                        }
                        else
                        {
                            s2.push(true);
                            root = temp1->right;
                            break;
                        }
                    }
                    else
                    {
                        if(temp1->val > temp_val)
                        {
                            temp = temp1;
                            temp_val = temp->val;
                        }
                        s1.pop();
                    }
                }
            }
        }
        return temp;
    }
    TreeNode * maxNode(TreeNode * root) {
        // write your code here
        // 递归法
        //return traverse1(root);
        // 非递归法(采用中序遍历)
        //return traverse2(root);
        // 非递归法(采用前序遍历)
        //return treverse3(root);
        // 非递归法(采用后序遍历)
        return traverse4(root);
    }
};
