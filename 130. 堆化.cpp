class Solution {
public:
    /*
     * @param A: Given an integer array
     * @return: nothing
     */
    // 最小堆
    void min_heapify(vector<int> &A, int parent)
    {
        int left = 2*parent + 1;
        int right = 2*parent + 2;
        int small = parent;
        if(left<=A.size()-1 && A[left]<A[small])
            small = left;
        if(right<=A.size()-1 && A[right]<A[small])
            small = right;
        if(parent!=small)
        {
            int temp = A[parent];
            A[parent] = A[small];
            A[small] = temp;
            min_heapify(A, small);
        }
    }
    void heapify(vector<int> &A) {
        // write your code here
        for(int i=(A.size()-2)/2; i>=0; i--)
            min_heapify(A, i);
    }
};
