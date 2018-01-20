class Solution {
public:
    /*
     * @param nums: A list of integer which is 0, 1 or 2
     * @return: nothing
     */
    int parttion(vector<int> &v, int low, int high)
    {
        int pivotkey = v[low];
        while(low<high)
        {
            while(low<high && pivotkey<=v[high])
                high--;
            v[low] = v[high];
            while(low<high && pivotkey>=v[low])
                low++;
            v[high] = v[low];
        }
        v[low] = pivotkey;
        return low;
    }

    void quickSort(vector<int> &v, int low, int high)
    {
        while(low<high)
        {
            int pivot = parttion(v, low, high);
            quickSort(v, low, pivot);
            low = pivot + 1;
        }
    }

    void sortColors(vector<int> &nums) {
        // write your code here
        quickSort(nums, 0, nums.size()-1);
    }
};
