/*
 * title：容易-167.链表求和
 * desc:你有两个用链表代表的整数，其中每个节点包含一个数字。
 *      数字存储按照在原来整数中相反的顺序，使得第一个数字位于链表的开头。
 *      写出一个函数将两个整数相加，用链表形式返回和。
 * e.g.:给出两个链表 3->1->5->null 和 5->9->2->null，返回 8->0->8->null
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
    /**
     * @param l1: the first list
     * @param l2: the second list
     * @return: the sum list of l1 and l2 
     */
    int insert(ListNode **head, ListNode **tail, int x)
    {
        ListNode *temp;
        if(*head == NULL || *tail == NULL)
        {
            temp = (ListNode *)malloc(sizeof(ListNode));
            if(temp != NULL)
            {
                temp->val = x;
                temp->next = NULL;
                *head = *tail = temp;
                return 1;
            }
        }
        else
        {
            temp = (ListNode *)malloc(sizeof(ListNode));
            if(temp != NULL)
            {
                temp->val = x;
                temp->next = NULL;
                (*tail)->next = temp;
                *tail = temp;
                return 1;
            }
        }
        return 0;
        
    }
    ListNode *addLists(ListNode *l1, ListNode *l2) {
        // write your code here
        ListNode *L1, *L2, *head, *tail;
        int sum, x, val1, val2;
        val1 = val2 = 0;
        sum = x =0;
        L1 = l1;
        L2 = l2;
        head = tail = NULL;
        while(1)
        {
            if(L1 == NULL && L2 == NULL)
            {
                if(x == 1)
                    insert(&head, &tail, x);
                break;
            }
            else if(L1 == NULL && L2 != NULL)
            {
                val1 = 0;
                val2 = L2->val;
                L2 = L2->next;
            }
            else if(L1 != NULL && L2 == NULL)
            {
                val1 = L1->val;
                val2 = 0;
                L1 = L1->next;
            }
            else
            {
                val1 = L1->val;
                val2 = L2->val;
                L1 = L1->next;
                L2 = L2->next;
            }
            
            sum = val1 + val2 + x;
            x = 0;
            if(sum >= 10)
            {
                x = 1;
                sum = sum - 10;
            }
            insert(&head, &tail, sum);
        }
        return head;
    }
};