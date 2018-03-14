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
