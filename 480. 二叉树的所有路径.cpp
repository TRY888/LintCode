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
     * @param root: the root of the binary tree
     * @return: all root-to-leaf paths
     */
    // string num2string(int num)
    // {
    //     char c_num;
    //     string str;
    //     if(num >= 0)
    //     {
    //         while(num>0)
    //         {
    //             c_num = (char)(num%10 + 48);
    //             str.insert(str.begin(), c_num);
    //             num = num/10;
    //         }
    //     }
    //     else
    //     {
    //         num = -num;
    //         while(num>0)
    //         {
    //             c_num = (char)(num%10 + 48);
    //             str.insert(str.begin(), c_num);
    //             num = num/10;
    //         }
    //         str.insert(str.begin(), '-');

    //     }

    //     return str;
    // }

    // vector<string> binaryTreePaths(TreeNode * root) {
    //     // write your code here
    //     vector<string> v1;
    //     string str;
    //     stack<TreeNode *> s1;
    //     stack<bool> s2;
    //     while(root!=NULL)
    //     {
    //         str.append(num2string(root->val));
    //         str.append("->");
    //         s1.push(root);
    //         s2.push(false);
    //         root = root->left;
    //         if(root == NULL)
    //         {
    //             while(!s1.empty())
    //             {
    //                 TreeNode *temp = s1.top();
    //                 int cnt = s2.top();
    //                 s2.pop();
    //                 if(cnt == false)
    //                 {
    //                     if(temp->right == NULL)
    //                     {
    //                         if(str.size()>2)
    //                             str.erase(str.size()-2, 2);
    //                         if(temp->left == NULL && temp->right == NULL)
    //                         {
    //                             v1.push_back(str);
    //                         }
    //                         string s = num2string(temp->val);
    //                         str.erase(str.size()-s.size(), s.size());
    //                         //cout << temp->val << " ";
    //                         s1.pop();
    //                     }
    //                     else
    //                     {
    //                         s2.push(true);
    //                         root = temp->right;
    //                         break;
    //                     }
    //                 }
    //                 else
    //                 {
    //                     if(str.size()>2)
    //                         str.erase(str.size()-2, 2);
    //                     if(temp->left == NULL && temp->right == NULL)
    //                     {
    //                         v1.push_back(str);
    //                     }
    //                     string s = num2string(temp->val);
    //                     str.erase(str.size()-s.size(), s.size());
    //                     //cout << temp->val << " ";
    //                     s1.pop();
    //                 }
    //             }
    //         }
    //     }
    //     return v1;
    // }
    vector<string> binaryTreePaths(TreeNode* root) {
        // Write your code here
        vector<string> res;
        if(root==NULL)
            return res;
        binaryTreePathsCore(root,res,to_string(root->val));
        return res;
    }

    void binaryTreePathsCore(TreeNode* root,vector<string> &str,string strpath)
    {
        if(root->left==NULL&&root->right==NULL)//叶子结点
        {
            str.push_back(strpath);
            return;
        }
        if(root->left!=NULL)
            binaryTreePathsCore(root->left,str,strpath+"->"+to_string(root->left->val));
        if(root->right!=NULL)
            binaryTreePathsCore(root->right,str,strpath+"->"+to_string(root->right->val));
    }
};
