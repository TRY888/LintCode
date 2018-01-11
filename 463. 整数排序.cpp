class Solution {
public:
    /*
     * @param A: an integer array
     * @return:
     */

    void swap(vector<int> &A, int p, int r)
    {
        int temp = A[p];
        A[p] = A[r];
        A[r] = temp;
    }

    // 冒泡排序
    void BubbleSort(vector<int> &A)
    {
        for(int i=0; i<A.size(); i++)
        {
            for(int j=0; j<A.size()-i-1; j++)
            {
                if(A[j] > A[j+1])
                {
                    swap(A, j, j+1);
                }
            }
        }
    }

    void sortIntegers(vector<int> &A) {
        // write your code here
        BubbleSort(A);
    }
};
