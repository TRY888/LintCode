class Solution {
public:
    /*
     * @param n: An integer
     * @param nums: An array
     * @return: the Kth largest element
     */
    int partition(vector<int> &A, int low, int high)
    {
        int pivotkey = A[low];
        while(low<high)
        {
            while(low<high && pivotkey>=A[high])
                high--;
            A[low] = A[high];
            while(low<high && pivotkey<=A[low])
                low++;
            A[high] = A[low];
        }
        A[low] = pivotkey;
        return low;
    }

    void QuickSort(vector<int> &A, int p, int r)
    {
        while(p<r)
        {
            int pivot = partition(A, p, r);
            QuickSort(A, p, pivot);
            p = pivot + 1;
        }
    }
    int kthLargestElement(int n, vector<int> &nums) {
        // write your code here
        QuickSort(nums, 0, nums.size()-1);
        return nums[n-1];
    }
};
