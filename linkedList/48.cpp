/*
 * title：中等-48.主元素 III
 * desc:给定一个整型数组，找到主元素，它在数组中的出现次数严格大于数组元素个数的1/k。
 * e.g.:数组中只有唯一的主元素
 *      给出数组 [3,1,2,3,2,3,3,4,4,4] ，和 k = 3，返回 3
 *      要求时间复杂度为O(n)，空间复杂度为O(k)
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    /*
     * @param nums: A list of integers
     * @param k: An integer
     * @return: The majority number
     */
    struct ListNode{
        int val;
        int cnt;
        ListNode *next;
        ListNode(int x, int c):val(x), cnt(c), next(NULL){}
    };
    
    void insert(ListNode **head, ListNode **tail, int value, int count)
    {
        if(*head == NULL)
        {
            ListNode *newNode = new ListNode(value, count);
            *tail = newNode;
            *head = newNode;
        }
        else
        {
            ListNode *newNode = new ListNode(value, count);
            (*tail)->next = newNode;
            *tail = newNode;
        }
    }
    
    bool isValueExistInList(ListNode *head, int value)
    {
        ListNode *p = head;
        while(p!=NULL)
        {
            if(p->val == value)
            {
                p->cnt++;
                return true;
            }
            p = p->next;
        }
        return false;
    }
    
    int findMaxValueInList(ListNode *head)
    {
        int value = 0, cnt = -1;
        ListNode *p = head;
        while(p!=NULL)
        {
            if(p->cnt > cnt)
            {
                value = p->val;
                cnt = p->cnt;
            }
            p = p->next;
        }
        return value;
    }
    
    int majorityNumber(vector<int> &nums, int k) {
        // write your code here
        ListNode *tail,*newHead;
        tail = newHead = NULL;
        int size = nums.size();
        for(int i=0; i<size; ++i)
        {
            if(isValueExistInList(newHead, nums[i]) == false)
                insert(&newHead, &tail, nums[i], 1);
        }
        return findMaxValueInList(newHead);
    }
};