/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */

    void min_heapify(int parent)
    {
        int left = 2*parent + 1;
        int right = 2*parent + 2;
        int smallest = parent;
        if(left<=heap_size-1 && heap[left]->val<heap[smallest]->val)
            smallest = left;
        if(right<=heap_size-1 && heap[right]->val<heap[smallest]->val)
            smallest = right;
        if(parent!=smallest)
        {
            ListNode *temp = heap[smallest];
            heap[smallest] = heap[parent];
            heap[parent] = temp;
            min_heapify(smallest);
        }
    }



    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // write your code here
        if(lists.size()==0)
            return NULL;
        heap.resize(lists.size());
        heap_size = 0;
        //将k个排序链表的头元素放入数组中
        for(int i=0; i<lists.size(); i++)
        {
            if(lists[i]!=NULL)
            {
                heap[heap_size] = lists[i];
                heap_size++;
            }
        }
        //将数组转化为最小堆
        for(int i=(heap_size-2)/2; i>=0; i--)
            min_heapify(i);
        ListNode *new_list = new ListNode(0);
        ListNode *new_list_next = new_list;
        while(heap_size>0)
        {
            new_list_next->next = heap[0];
            cout << heap[0]->val << endl;
            new_list_next = new_list_next->next;
            if(heap[0]->next!=NULL)
            {
                heap[0] = heap[0]->next;
                min_heapify(0);
            }
            else
            {
                heap_size--;
                if(heap_size>0)
                {
                    heap[0] = heap[heap_size];
                    min_heapify(0);
                }
            }
        }
        ListNode *temp = new_list->next;
        delete new_list;
        return temp;
    }
private:
    vector<ListNode*> heap;
    int heap_size;
};


