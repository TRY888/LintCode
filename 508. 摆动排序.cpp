class Solution {
public:
    /*
     * @param nums: A list of integers
     * @return: nothing
     */
    int partition(vector<int> &nums, int low, int high)
    {
        int pivotkey = nums[low];
        while(low < high)
        {
            while(low < high && pivotkey <= nums[high])
                high--;
            nums[low] = nums[high];
            while(low < high && pivotkey >= nums[low])
                low++;
            nums[high] = nums[low];
        }
        nums[low] = pivotkey;
        return low;
    }

    void quickSort(vector<int> &nums, int low, int high)
    {
        while(low<high)
        {
            int pivot =  partition(nums, low, high);
            quickSort(nums, low, pivot);
            low = pivot + 1;
        }
    }

    // 如果数组个数为偶数，则将数组倒数第二个元素和数组正数第二个元素互换，步长为2
    // 如果数组个数为奇数，则将数组倒数第一个元素和数组正数第一个元素互换，步长为2
    void wiggleSort(vector<int> &nums) {
        // write your code here
        quickSort(nums, 0, nums.size()-1);
        if(nums.size()%2 == 0)
        {
            int i = 1;
            int j = nums.size()-2;
            while(i<j)
            {
                int temp = nums[j];
                nums[j] = nums[i];
                nums[i] = temp;
                j = j - 2;
                i = i + 2;
            }
        }
        else
        {
            int i = 1;
            int j = nums.size()-1;
            while(i<j)
            {
                int temp = nums[j];
                nums[j] = nums[i];
                nums[i] = temp;
                j = j - 2;
                i = i + 2;
            }
        }
    }
};
