class Solution {
public:
    /*
     * @param matrix: a matrix of integers
     * @param k: An integer
     * @return: the kth smallest number in the matrix
     */

    // 时间复杂度O(log(n))
    void min_heapify(int parent)
    {
        int left = 2*parent + 1;
        int right = 2*parent + 2;
        int smallest = parent;
        if(left<=heap_size-1 && heap[left].val<heap[smallest].val)
            smallest = left;
        if(right<=heap_size-1 && heap[right].val<heap[smallest].val)
            smallest = right;
        if(parent!=smallest)
        {
            Node temp = heap[smallest];
            heap[smallest] = heap[parent];
            heap[parent] = temp;
            min_heapify(smallest);
        }
    }


    int kthSmallest(vector<vector<int>> matrix, int k) {
        // write your code here
        int row_max = matrix.size();
        int col_max = 0;
        heap_size = 0;
        if(row_max!=0)
        {
            col_max = matrix[0].size();
            if(row_max>=col_max)
            {
                heap.resize(row_max);
                //将矩阵每一行的头元素写入数组
                for(int i=0; i<row_max; i++)
                {
                    heap[i] = Node(matrix[i][0], i, 0);
                    heap_size++;
                }
                //将数组转化为最小堆
                for(int i=(heap_size-2)/2; i>=0; i--)
                    min_heapify(i);
                int cnt = 0;
                Node node(0, 0, 0);
                while(heap_size>0 && cnt<k)
                {
                    node = heap[0];
                    if(heap[0].col<col_max-1)
                    {
                        heap[0] = Node(matrix[heap[0].row][heap[0].col+1],
                                       heap[0].row, heap[0].col+1);
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
                    cnt++;
                }
                return node.val;

            }
            else
            {
                heap.resize(col_max);
                //将矩阵每一列的头元素写入数组
                for(int i=0; i<col_max; i++)
                {
                    heap[i] = Node(matrix[0][i], 0, i);
                    heap_size++;
                }
                //将数组转化为最小堆
                for(int i=(heap_size-2)/2; i>=0; i--)
                    min_heapify(i);
                int cnt = 0;
                Node node(0, 0, 0);
                while(heap_size>0 && cnt<k)
                {
                    node = heap[0];
                    if(heap[0].row<row_max-1)
                    {
                        heap[0] = Node(matrix[heap[0].row+1][heap[0].col],
                                       heap[0].row+1, heap[0].col);
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
                    cnt++;
                }
                return node.val;
            }
        }
        else
        {
            return matrix[0][k-1];
        }
    }
private:
    struct Node{
        int val;
        int row;
        int col;
        Node(){}
        Node(int val, int row, int col){
            this->val = val;
            this->row = row;
            this->col = col;
        }
    };
    vector<Node> heap;
    int heap_size;
};
