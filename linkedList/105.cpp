/*
 * title：中等-105.复制带随机指针的链表
 * desc:给出一个链表，每个节点包含一个额外增加的随机指针可以指向链表中的任何节点或空的节点。
 *      返回一个深拷贝的链表。 
 * e.g.:
 */

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head: The head of linked list with a random pointer.
     * @return: A new head of a deep copy of the list.
     */
    void insert(RandomListNode **tail, int val, RandomListNode *rand)
    {
        RandomListNode *newNode = new RandomListNode(val);
        newNode->next = NULL;
        newNode->random = rand;
        (*tail)->next = newNode;
        *tail = newNode; 
    }
     
    RandomListNode *copyRandomList(RandomListNode *head) {
        // write your code here
        RandomListNode *newHead = new RandomListNode(0);
        newHead->next = NULL;
        newHead->random = NULL;
        RandomListNode *p, *temp, *tail;
        p = head;
        tail = newHead;
        while(p!=NULL)
        {
            insert(&tail, p->label, p->random);
            p = p->next;
        }
        temp = newHead->next;
        delete newHead;
        return temp;
        
    }
};