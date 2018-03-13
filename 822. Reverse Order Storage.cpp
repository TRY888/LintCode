class Solution {
public:
    /**
     * @param head: the given linked list
     * @return: the array that store the values in reverse order
     */
    vector<int> reverseStore(ListNode * head) {
        // write your code here
        vector<int> res;
        while(head!=NULL)
        {
            res.insert(res.begin(), head->val);
            head = head->next;
        }
        return res;
    }
};
